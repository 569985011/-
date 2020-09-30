import turtle,time

def drawLine(down):
    turtle.fd(3)
    turtle.pd() if down else turtle.pu()
    turtle.fd(35)
    turtle.pu()
    turtle.fd(3)          
    turtle.right(90)
    

def drawDigit(digit):
    drawLine(False) if digit in [0,1,7,' ','C'] else drawLine(True)
    drawLine(False) if digit in [2,' ','C','E','F'] else drawLine(True)
    drawLine(False) if digit in [1,4,7,' ','A','F'] else drawLine(True)
    drawLine(False) if digit in [1,3,4,5,7,9,' '] else drawLine(True)
    turtle.left(90)
    drawLine(False) if digit in [1,2,3,7,' ','d'] else drawLine(True)
    drawLine(False) if digit in [1,4,' ','b','d'] else drawLine(True)
    drawLine(False) if digit in [5,6,' ','b','C','E','F'] else drawLine(True)
    #返回起点，重置方向
    drawLine(False)
    turtle.right(90)
    
def drawDate(string):
    for i in string:
        if i in [' ','A','b','C','d','E','F']:
            drawDigit(i)
        elif i in ['1','2','3','4','5','6','7','8','9','0']:
            drawDigit(int(i))
        else:
            turtle.write(i,font=('Arial',20,'normal'))
        turtle.fd(60)
        

turtle.setup(800,350,200,0)
turtle.pu()
turtle.fd(-380)
turtle.pencolor("black")

drawDate(time.strftime("%Y年%m月%d日",time.gmtime()) )
