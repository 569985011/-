with open('latex.log', 'r', encoding='utf-8') as f:
    l=f.readlines()
    s=set(l)
    l=list(s)
    print('共'+str(len(l))+'独特行')