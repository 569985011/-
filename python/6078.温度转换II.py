a=input()

if a[0] in ['F','f']:
    C=eval(a[1:-1])-32/1.8
    print("C{:.2f}".format(C))
elif a[0] in ['C','c']:
    F=eval(a[1:-1])*1.8+32
    print("F{:.2f}".format(F))
