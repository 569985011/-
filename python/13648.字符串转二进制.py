import sys


def str2binary(s):
    for k in s:
        k=bytes(s,"utf-8")
        
            
    return ' '.join(format(bink,'08b') for bink in k)
    


for line in sys.stdin:
    print(str2binary(line))

