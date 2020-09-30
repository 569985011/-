
who=(18.5,25,30,)
cn=(18.5,24,28,)

word=('偏瘦','正常','偏胖','肥胖')


h,w = eval(input())


bmi=round(w/h/h, 2)

print("BMI数值为:",bmi)

lenw=len(list(filter(lambda x: x <= bmi,who)))
lenc=len(list(filter(lambda x: x <= bmi,cn)))

print("BMI指标为:国际'{}', 国内'{}'".format(word[lenw],word[lenc]))

