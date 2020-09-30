import itertools
import sys

a="零一二三四五六七八九"
zero="零十百千万亿"

def num2chinese(num, big=False, simp=True, o=False, twoalt=False):
    #寻找小数点
    dian=num.find('.')    
    #输出正负号
    Index=0               
    if num[Index]=='-':
        print("负",end='')
        Index=1
    #分别处理整数与小数部分
    ZhengShu=num[Index:]
    XiaoShu=''
    if dian>-1:
        XiaoShu=num[dian:]
        ZhengShu=num[Index:dian]
    
    return Qulin(Zhengshu(ZhengShu))+Xiaoshu(XiaoShu)
    
def Qulin(temp):#对整数部分去零整理
    if len(temp)<2:return temp
    for i in range(len(temp)-1,1,-1):
        if temp[i] in zero and temp[i-1]=='零':
            temp=temp[0:i-1]+temp[i:len(temp)]
    for i in range(len(temp)-1,1,-1):
        if temp[i]=='万' and temp[i-1]=='亿':
            temp=temp[0:i]+ temp[i+1:]
        
    if temp[-1]=='零':
        temp=temp[:-1]
    if temp[0]=='一' and temp[1]=='十' :
        temp=temp[1:]
    return temp
def Zhengshu(num):
    temp=""
    if len(num)>8:
        temp+=Zhengshu(num[0:len(num)-8])+'亿'
        num=num[len(num)-8:]
    if len(num)>4:
        temp+=Zhengshu(num[0:len(num)-4])
        temp+='万'   #稍后补充处理零
        num=num[len(num)-4:]
    if len(num)>3:
        if(num[0]!='0'):
            temp+=a[int(num[0])]+'千'
        else:
            temp+='零'  #稍后补充处理零
        num=num[1:]
    if len(num)>2:
        if(num[0]!='0'):
            temp+=a[int(num[0])]+'百'
        else:
            temp+='零'  #稍后补充处理零
        num=num[1:]
    if len(num)>1:
        if(num[0]!='0'):
            temp+=a[int(num[0])]+'十'
        else:
            temp+='零'  #稍后补充处理零
        num=num[1:]
    if len(num)==1:
        if(num[0]!='0'):
            temp+=a[int(num[0])]
        else:
            temp+='零'  #稍后补充处理零
        
    return temp

    
def Xiaoshu(num):
    if len(num)==0:return ''
    temp='点'
    for i in num[1:]:
        temp+=a[int(i)]
    return temp
    
for line in sys.stdin:
    print(num2chinese(line.strip()))
