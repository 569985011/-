import requests,re
from bs4 import BeautifulSoup
import bs4

def GetHTMLText(url):
    header={'User-Agent': '''Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.132 Safari/537.36'''}
    
    try:
        r=requests.get(url,headers=header)
        r.raise_for_status()
        r.encoding = r.apparent_encoding   #设置编码方案为网页编码属性
        soup=BeautifulSoup(r.text,'html.parser')
        return soup
    except:
        print("产生异常")
        


def fillUnivList(soup):    #自己思路写的
    ulist=[]
    
    Name=soup.find_all('div',attrs={'align':'left'},string=re.compile("大学"))
    Score=soup.find_all('td',class_="hidden-xs need-hidden indicator5")
    for i in range(len(Name)):
        ulist.append([i+1,Name[i].string,Score[i].string])
    return ulist

def fillUnivList2(soup,num=10):    #老师给的参考代码
    ulist=[]
    tbody=soup.find('tbody').children
    for tr in tbody:
        if isinstance(tr,bs4.element.Tag):
            tds = tr('td')
            ulist.append([tds[0].string,tds[1].string,tds[4].string])
    return ulist


def printUnivList(ulist,num):
    printTample="{0:^10}\t{1:{3}^6}\t{2:^10}"   #{3}用于标识将chr(12288)用于{1}中的填充
    for i in range(len(ulist)if len(ulist)<num else num):
        print(printTample.format(ulist[i][0],ulist[i][1],ulist[i][2],chr(12288)))

def main():
    url="http://www.zuihaodaxue.cn/zuihaodaxuepaiming2016.html"
    soup=GetHTMLText(url)

    printUnivList(fillUnivList(soup),20)

    printUnivList(fillUnivList2(soup),20)


    
main()
