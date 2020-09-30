from turtle import *
import math
def DrawPolygon(lenth,Edges):
    pu()
    fd(lenth/-2)
    left(90)
    fd(  math.tan(180-Edges)*lenth/2 )
    right(90)
    pd()
    for i in range(Edges):
        fd(lenth)
        left(360/Edges)
    




DrawPolygon(100,5)
#返回多边形中心
pu()
goto(0,0)
pd()
#旋转角度叠加
left(100)
DrawPolygon(100,5)
