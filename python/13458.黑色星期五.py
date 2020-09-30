import datetime


def black_friday():
    a=[]
    for i in range(1950,2051):
        for j in range(1,13):
            if(datetime.date(year=i,month=j,day=13).weekday()==4):
                a.append(datetime.date(i,j,13))
    return a

for date in black_friday():
    print(date.strftime('%Y-%m-%d'))
