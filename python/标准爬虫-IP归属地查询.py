import requests
from bs4 import BeautifulSoup

header={'User-Agent': '''Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.132 Safari/537.36'''}
url='https://python123.io/ws/demo.html'
vt={}

try:
    r=requests.get(url,headers=header)
    r.status_code
    soup=BeautifulSoup(r.text,'html.parser')
    print(soup.prettify())    
except:
    
    print("请求失败")
