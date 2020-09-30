import requests
import os

url = "https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1584360774536&di=38dcd8c4437975b0a690d1d8ddeea254&imgtype=0&src=http%3A%2F%2Fbbsimg.feidee.com%2Fdata%2Fattachment%2Fforum%2F201310%2F10%2F083832pl5ax5la25cjja2a.jpg"
path = "C://Users//Administrator//Pictures//"
path+= url.split('%')[-1]

try:
    if not os.path.exists(root):
        os.mkdir(root)
    if not os.path.exists(path):
        r=requests.get(url)
        with open(path,'wb') as f:
            f.write(r.content)
            f.close()
            print('文件保存成功')
    else:
        print("文件已存在")
except:
    print("请求失败")
