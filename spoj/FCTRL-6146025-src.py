def fctrl(n):
    i=1
    m=0
    t=1
    while t<n:
        t=5**i
        m+=n/t
        i+=1
    return m
 
t=int(input())
for i in range(t):
    x=int(input())
    print fctrl(x)