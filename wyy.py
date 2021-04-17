import requests
from bs4 import BeautifulSoup
headers={'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/74.0.3729.131 Safari/537.36'}
while(1):
    url=input()
    out=requests.get("http://music.163.com/song/media/outer/url?id="+url+".mp3",headers=headers,timeout=20)
    mus=out.content
    print("good")
    with open(r"d:/Downloads/Music/"+url+".mp3",'ab') as file:
        file.write(mus)
        file.flush()
