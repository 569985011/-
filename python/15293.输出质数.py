def prime(m):
    m=int(m)-1
    a=''
    num=0
    while(True):
        m+=1
        if m%2==0:
            continue 
        for i in range(3,m,2):
            if(m%i==0):
                break 
        else:
            a+=str(m)+','
            num+=1 
            if(num>4):
                break 
    return a[:-1]
        
n = eval(input())
prime(int(n))
