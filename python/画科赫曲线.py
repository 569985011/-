import turtle


def koch(lenth,n):
    if n==0:
        turtle.fd(lenth)
    else:
        for angle in [0,60,-120,60]:
            turtle.left(angle)
            koch(lenth/3,n-1)




def main():
    turtle.speed(20)
    turtle.setup(800,750)
    turtle.pu()
    turtle.goto(-300,200)
    turtle.pd()
    turtle.pensize(2)
    for i in range(3):
        koch(600,4)
        turtle.right(120)
    turtle.hideturtle()

main()
