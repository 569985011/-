import random
import string

random.seed(0)

def generate_password(length):
    #
    a="abcdefghijklmnopqrstuvwxyz""ABCDEFGHIJKLMNOPQRSTUVWXYZ""0123456789"
    k=""
    for i in range(length):
        k+=(random.choice(a))
    return k
    
print(generate_password(5))
print(generate_password(8))
print(generate_password(10))

