#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2018-10-04 21:59:53
# @Author  : Chauncy (chauncy523@gmail.com)
# @Link    : 
# @Version : $Id$
#TempConvert.py
val = input("请输入带温度表示符号的温度值(例如:32C)")
if val[-1] in ('c','C'):
   f = 1.8 * float(val[0:-1]) + 32
   print ("转换后的温度为：%.2fF"%f)
elif val[-1] in ('F','f'):
	c = (float(val[0:-1])-32)/1.8
	print("转换后的温度维：%.2fC"%c)
else: print ("输入有误")


