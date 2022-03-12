from collections import Counter as ct

for _ in range(int(input())):
    n,y=list(map(int,input().split()))
    a=list(map(int,input().split()))
    d=ct(a)
    ans=0

    if y==1:
        for x in d.values():
            if x%2==1:
                ans=ans+1
            
        print(ans)
    else:
        for x in d.keys():
        
            #a=y*x
            if d[y*x]!=0:
                if d[x]>d[y*x]:
                    d[x]=d[x]-d[y*x]
                    d[y*x]=0
                
 
                else:
                    d[y*x]=d[y*x]-d[x]
                    d[x]=0
                
 
        for x in d.values():
        
            ans=ans+x
 
        print(ans)