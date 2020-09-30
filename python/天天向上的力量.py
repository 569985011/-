def dayup(df,study):
    dayup=1
    for i in range(365):
        if i%7 in study:
            dayup*=1+df
        else:    
            dayup*=1-0.01
                    
    return dayup

flag=dayup(0.01,[0,1,2,3,4,5,6])
Fire=0.01
while flag>dayup(Fire,[1,2,3,4,5]):
    Fire+=0.001
    

print("工作日的努力参数是: {:.3f}".format(Fire))
