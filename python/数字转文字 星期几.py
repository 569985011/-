
temp=["星期日","星期一","星期二","星期三","星期四","星期五","星期六"]
temp2="日一二三四五六"
while True:
    a=input("请输入数字1~7中任意一个整数")
    print(temp[int(a)%7])
    print("星期"+temp2[int(a)%7])
    
