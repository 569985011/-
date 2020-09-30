#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2018-02-18
# @Author  : ${author} (${email})
# @Link    : ${link}
# @Version : $Id$
import turtle
#等边三角形

turtle.pencolor("green")
turtle.pensize(5)
turtle.seth(0)
turtle.forward(300)
turtle.seth(120)
turtle.forward(300)
turtle.seth(240)
turtle.forward(300)

#手动花园
# turtle.pencolor("blue")
#turtle.fillcolor("purple")
# for i in range(360):
# 	turtle.seth(i)
# 	turtle.forward(2)

#填充法画图
from turtle import *
color('yellow','red')
begin_fill()
while True:
	forward(500)
	right(144)
	if(abs(pos()))<1:
		break
end_fill()

#九九乘法表
for i in range(1,10):
	for j in range(1,i+1):
		print(i,'*',j,'=',i*j,end='\t')
	print('')
print(type(i))
print("-----------------------")

#计算（1+2！+3！……+N!）
n=input("请输入整数N,我们将为您计算阶乘和:")	
sum=0
flag=1
for i in range(1,int(n)+1):
	flag*=i
	sum+=flag
print(sum)

print("-----------------------")

#计算（1+2+3+……+N)
n=input("请输入整数N,我们将为您计算他的累加和:")
sum=0
for i in range(int(n)):
	sum+=i+1
print(sum)

