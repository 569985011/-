with open('latex.log', 'r', encoding='utf-8') as f:
    counts={}
    Total=0
    key=f.read(1)
    while(key!=''):
        if key in "abcdefghijklmnopqrstuvwxyz":
            counts[key]=counts.get(key,0)+1
        key=f.read(1)
        Total+=1
    print('共'+str(Total)+'字符',end='')
    l=list(counts.items())
    l.sort(key=lambda x:x[0],reverse=False)
    for i in l:
        print(r',{}:{}'.format(i[0],i[1]),end='')
