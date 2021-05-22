# 网易云 根据歌单链接下载MP3歌曲
import requests
from bs4 import BeautifulSoup
import re

headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/74.0.3729.131 Safari/537.36'}

def main():
    url = "https://music.163.com/#/playlist?id=6767501416" # 歌单地址 请自行更换
    if '/#/' in url:
        url = url.replace('/#/', '/')

    s = requests.session()
    try:
        response = s.get(url, headers=headers).content
        soup = BeautifulSoup(response, 'lxml')
        lis = list(soup.find('ul'))
        fatherlis = ['歌单名：' + str(soup.find('h2').string)]
        for i in lis:
            sonlis = []
            sonlis.append(str(len(fatherlis)) + '.')
            sonlis.append(i.a.string)
            sonlis.append(str(i.a.get('href'))[str(i.a.get('href')).find('=') + 1:-1] + str(i.a.get('href'))[-1])
            fatherlis.append(sonlis)
    except:
        print("\n\t歌曲链接输入错误")
        exit('ERROR!')
    format = '{0:<10}\t{1:{3}<10}\t{2:<10}'
    print("从'{}'中找到了{}条歌曲".format(str(soup.find('h2').string), len(fatherlis) - 1))
    print('-------------------------------------------------------------------------------------------------')
    print('序号         歌曲名称        歌曲链接')
    for i in fatherlis:
        if fatherlis.index(i) == 0:
            continue
        else:
            print(
                format.format(i[0], i[1], 'http://music.163.com/song/media/outer/url?id=' + i[2] + '.mp3', chr(12288)))
            download_music(i[2],i[1])
    print('##########################下载完成##########################')

# 歌曲下载
def download_music(song_id,song_name):
    song_name=re.sub("[\\/:\\*\\?\"<>|]","",song_name)
    out=requests.get("http://music.163.com/song/media/outer/url?id="+song_id+".mp3",headers=headers,timeout=20)
    mus=out.content
    print("good")
    with open(r"d:/Downloads/Music/"+song_name+".mp3",'ab') as file:
        file.write(mus)
        file.flush()

if __name__ == '__main__':
    main()
