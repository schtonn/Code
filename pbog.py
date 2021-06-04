# -*- encoding: utf-8 -*-
import requests
import json
from bs4 import BeautifulSoup
import execjs 
from urllib import parse
import time
 
class Py4Js():
    def __init__(self):
        self.ctx = execjs.compile(""" 
        function TL(a) { 
        var k = ""; 
        var b = 406644; 
        var b1 = 3293161072; 
        var jd = "."; 
        var $b = "+-a^+6"; 
        var Zb = "+-3^+b+-f"; 
        for (var e = [], f = 0, g = 0; g < a.length; g++) { 
            var m = a.charCodeAt(g); 
            128 > m ? e[f++] = m : (2048 > m ? e[f++] = m >> 6 | 192 : (55296 == (m & 64512) && g + 1 < a.length && 56320 == (a.charCodeAt(g + 1) & 64512) ? (m = 65536 + ((m & 1023) << 10) + (a.charCodeAt(++g) & 1023), 
            e[f++] = m >> 18 | 240, 
            e[f++] = m >> 12 & 63 | 128) : e[f++] = m >> 12 | 224, 
            e[f++] = m >> 6 & 63 | 128), 
            e[f++] = m & 63 | 128) 
        } 
        a = b; 
        for (f = 0; f < e.length; f++) a += e[f], 
        a = RL(a, $b); 
        a = RL(a, Zb); 
        a ^= b1 || 0; 
        0 > a && (a = (a & 2147483647) + 2147483648); 
        a %= 1E6; 
        return a.toString() + jd + (a ^ b) 
    }; 
    function RL(a, b) { 
        var t = "a"; 
        var Yb = "+"; 
        for (var c = 0; c < b.length - 2; c += 3) { 
            var d = b.charAt(c + 2), 
            d = d >= t ? d.charCodeAt(0) - 87 : Number(d), 
            d = b.charAt(c + 1) == Yb ? a >>> d: a << d; 
            a = b.charAt(c) == Yb ? a + d & 4294967295 : a ^ d 
        } 
        return a 
    } 
    """)

    def getTk(self, text):
        return self.ctx.call("TL", text)
class Translate_as_google(object):
    def __init__(self, to_language, this_language='auto', read=False):
        '''
            to_language:要翻译成的语言
            this_language:要转换的文字,默认为auto自动
            read:在指定位置生成text的朗读文件
        '''
        self.this_language = this_language
        self.to_language = to_language
        self.read = read
 
    def open_url(self, url):
        '''请求'''
        headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; WOW64; rv:23.0) Gecko/20100101 Firefox/23.0'}
        req = requests.get(url=url, headers=headers , timeout=8)
 
        return req
 
    def buildUrl(self):
        '''封装请求url
            sl:要转换的文字 tl:转换的结果类型 q要输入的文字'''
        baseUrl = 'http://translate.google.cn/translate_a/single'
        baseUrl += '?client=webapp&'
        baseUrl += 'sl=%s&' % self.this_language
        baseUrl += 'tl=%s&' % self.to_language
        baseUrl += 'hl=zh-CN&'
        baseUrl += 'dt=at&'
        baseUrl += 'dt=bd&'
        baseUrl += 'dt=ex&'
        baseUrl += 'dt=ld&'
        baseUrl += 'dt=md&'
        baseUrl += 'dt=qca&'
        baseUrl += 'dt=rw&'
        baseUrl += 'dt=rm&'
        baseUrl += 'dt=ss&'
        baseUrl += 'dt=t&'
        baseUrl += 'ie=UTF-8&'
        baseUrl += 'oe=UTF-8&'
        baseUrl += 'clearbtn=1&'
        baseUrl += 'otf=1&'
        baseUrl += 'pc=1&'
        baseUrl += 'srcrom=0&'
        baseUrl += 'ssel=0&'
        baseUrl += 'tsel=0&'
        baseUrl += 'kc=2&'
        baseUrl += 'tk=' + str(self.tk) + '&'
        baseUrl += 'q=' + parse.quote(self.text)
        return baseUrl
 
    def read_go(self, args):
        '''朗读截取
        upload:下载到路径及文件名称
        return_language:返回的语言类型
        '''
        upload, return_language = args[0], args[1]
        read_translate_url = 'http://translate.google.cn/translate_tts?ie=UTF-8&q=%s&tl=%s&total=1&idx=0&textlen=3&tk=%s&client=webapp&prev=input' % (
            self.text, return_language, self.tk)
        data = self.open_url(read_translate_url) #请求的返回所有数据
        with open(upload, 'wb') as f:
            f.write(data.content)
 
    def translate(self,text):
        '''翻译截取'''
        self.text = text
        js = Py4Js()
        self.tk = js.getTk(self.text)
 
        if len(self.text) > 4891:
            raise ("翻译的长度超过限制！！！")
        url = self.buildUrl()
        # print(url)
        _result = self.open_url(url)
        data = _result.content.decode('utf-8')
 
        tmp = json.loads(data)
        jsonArray = tmp[0]
        result = None
        for jsonItem in jsonArray:
            if jsonItem[0]:
                if result:
                    result = result + " " + jsonItem[0]
                else:
                    result = jsonItem[0]
        return result
 
if __name__ == '__main__':
    langs = ["en","zh-CN","en","la","ja","ru","de","la","zh-CN"]
    text = """游之日，风日清和，湖平于熨，时有小舫往来，如蝇头细字，着鹅溪练上。取酒共酌，意致闲淡，亭午风渐劲，湖水汩汩有声。千帆结阵而来，亦甚雄快。日暮，炮车云生，猛风大起，湖浪奔腾，雪山汹涌，震撼城郭。予始四望惨淡，投箸而起，愀然以悲，泫然不能自已也。"""
    print(text+'\n')
    for i in langs:
        ts = Translate_as_google(i)
        text = ts.translate(text)
        print(i+': '+text+'\n')