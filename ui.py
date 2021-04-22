import requests
from requests.exceptions import ConnectionError,Timeout

headers = {
'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/74.0.3729.131 Safari/537.36'
}

for i in "defghijklmnopqrstuvwxyz":
    for j in "abcdefghijklmnopqrstuvwxyz":
        try: print(requests.get("https://"+i+"91"+j+".com",headers=headers,timeout=2))
        except ConnectionError:
            print("fail"+i+j)
        except Timeout:
            print("time"+i+j)