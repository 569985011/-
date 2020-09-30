from turtle import *

def DrowWindmill(R,Edges):
    left(180/Edges)
    for i in range(Edges):
        fd(R)
        left(90)
        circle(R,360/Edges/2)
        left(-90)
        fd(-R)
        left(360/Edges/2)


DrowWindmill(50,4)
