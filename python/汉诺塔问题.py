
count=0
def hanoi(n,src,mid,dst):
    global count
    if n==1:
        print("{}:{}->{}".format(n,src,dst))
        count+=1
    else:
             
        hanoi(n-1,src,dst,mid)
        print("{}:{}->{}".format(n,src,dst))   
        count+=1
        
        hanoi(n-1,mid,src,dst)


for i in range(1,5):
    hanoi(i,'A','B','C')
    print("-----------")
        
