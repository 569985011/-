from turtle import *

def DrawTaiJi(R,r):
    #太极中心下移
    pu()
    right(90)
    fd(R)
    left(90)
    pd()
    #大圆
    circle(R)
    #太极鱼
    circle(R/2,180)
    circle(-1*R/2,180)
    #上鱼眼
    pu()
    right(90)
    fd(R/2-r)
    right(90)
    pd()
    circle(r)
    #下鱼眼
    left(90)
    pu()
    fd(R)
    right(90)
    pd()
    circle(r)
   
    
DrawTaiJi(200,20)

