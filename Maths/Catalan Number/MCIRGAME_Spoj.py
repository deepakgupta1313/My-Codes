def fac(n):
    if(n==0):
        return 1
    else:
        return n*fac(n-1)
while(True):
    k=input()
    if(k==-1):
        break
    else:
        temp=fac(2*k)/(fac(k+1)*fac(k))
        print temp
