with open('data.csv', 'r', encoding='utf-8') as f:
    L=list()
    for line in f:
        line=line.replace("\n","")
        line=line.replace(" ","")
        data=line.split(',')
        #print("=={}==".format(data))        
        line=";".join(data[::-1])
        L.append(line)
        
    for i in range(len(L)):
        print(L[len(L)-1-i])
