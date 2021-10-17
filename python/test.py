from urllib.request import urlopen
from bs4 import BeautifulSoup
import sys
# f=open("myprint2.txt","w+")
# sys.stdout=f
print(1145141919810)
for i in range(1,110):
    html = urlopen('https://www.cstam.org.cn/searchArticle/%E7%BA%AA%E8%A6%81/'+str(i)+'.html')
    bsObj = BeautifulSoup(html, 'html.parser')
    p=bsObj.find('ul',class_='my-list')
    t1 = p.find_all('a')
    for t2 in t1:
        if(t2.text.find('趣味')!=-1):
            print(t2.text)
            href = t2.get('href')
            print('https://www.cstam.org.cn'+href)