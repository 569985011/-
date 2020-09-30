def IsPrime(num):
    if num==2 :
        return True
    for i in range(3,num):
        if(num%i==0):
            return False
    return True
    
sum=2+3    
for i in range(5,100,2):
    if(IsPrime(i)):
        sum+=i
        print(i)
        
print(sum)
