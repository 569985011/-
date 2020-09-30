#TempConvert.py
#华氏度与摄氏度温度转换

TempStr = input("请输入带有符号的温度值：（例：35C  66F  ）")
if TempStr[-1] in ['F','f']:
    C = (eval(TempStr[0:-1]) -32)/1.8
    print("转换后的温度是{:.2f}C".format(C))
elif TempStr[-1] in ['C','c']:
    F = eval(TempStr[0:-1])*1.8+32
    print("转换后的温度是{.2f}".format(F))
else:
    print("格式错误！请查证后重新运行本程序。")
