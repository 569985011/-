a= input()
if a[0] in ['R']:
    USD=eval(a[3:])/6.78
    print("USD{:.2f}".format(USD))
elif a[0]in ['U']:
    RMB=eval(a[3:])*6.78
    print("RMB{:.2f}".format(RMB))
