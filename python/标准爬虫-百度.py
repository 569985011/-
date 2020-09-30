import requests

def getHTMLText(url,params=None):
    header={'User-Agent': '''Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.132 Safari/537.36'''}
    try:
        r=requests.get(url,params=params,headers=header)
        r.raise_for_status()
        r.encoding = r.apparent_encoding   #设置编码方案为网页编码属性
        
        return r.text[:1000]
    except:
        return "产生异常"

if __name__== '__main__':
    kv={'wd':'python'}
    url="https://www.baidu.com/s"
    print(getHTMLText(url,params=kv))
