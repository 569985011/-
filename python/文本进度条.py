import time

width=55
start=time.perf_counter()
print("进度条".center(width,"+"))
for i in range(width+1):
    left=i*'*'
    right=(width-i)*'-'
    dur=time.perf_counter()-start
    print("\r{:8.2%}[{}/{}]计时{}s".format(i/width,left,right,dur),end="")
    time.sleep(0.1)
print()
print("ENDING".center(width,'+'))    
