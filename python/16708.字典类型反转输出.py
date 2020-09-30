a=eval(input())
if type(a) == dict :
    print(r"{",end='')
    Flag=False
    for item in a.keys():
        
        if(Flag):
            print(', ',end='')
        else:
            Flag=True
        
        if type(item) ==str :
            print(r"{}: '{}'".format(a[item],item),end='')
        else:
            print(r"'{}': {}".format(a[item],item),end='')
    print(r"}",end='')
else:
    print("输入错误")
