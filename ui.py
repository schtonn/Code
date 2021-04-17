import requests
from bs4 import BeautifulSoup
import urllib.request
import re
import lxml

headers = {
'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/74.0.3729.131 Safari/537.36'
}

# 歌单的url地址
play_url = 'http://music.163.com/playlist?id='+input()

# 获取页面内容
s = requests.session()
response=s.get(play_url,headers = headers).content
 
#使用bs4匹配出对应的歌曲名称和地址
s = BeautifulSoup(response,'lxml')
main = s.find('ul',{'class':'f-hide'})
 
 
lists=[]

print(main.find_all('a'))

for music in main.find_all('a'):
    list=[]
    # print('{} : {}'.format(music.text, music['href']))
    musicUrl='http://music.163.com/song/media/outer/url'+music['href'][5:]+'.mp3'
    musicName=music.text
    # 单首歌曲的名字和地址放在list列表中
    list.append(musicName)
    list.append(musicUrl)
    # 全部歌曲信息放在lists列表中
    lists.append(list)
 
# 下载列表中的全部歌曲，并以歌曲名命名下载后的文件，文件位置为当前文件夹
for i in lists:
    url=i[1]
    name=re.sub("[\\/:\\*\\?\"<>|]","",i[0])
    print(name)
    print(url)
    out=requests.get(url+".mp3",headers=headers,timeout=20)
    mus=out.content
    # print(mus)
    print("good")
    with open(r"d:/Downloads/Music/"+name+".mp3",'ab') as file:
        file.write(mus)
        file.flush()