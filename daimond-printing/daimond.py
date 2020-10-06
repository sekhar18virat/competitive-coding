n=int(input())
c=0
for i in range(n):
    for j in range(n-i):
        print(" ",end=" ")
    if(i!=0):
        j=1
        print("*",end=" ")
        c+=1
        while(j<=c):
            print("*",end=" ")
            if(j!=1):
                print("*",end=" ")
            j+=2
        print("*")
        c+=1
    else:
        print("*")
x=1
j-=4
while(j>=-1):
    for i in range(x+1):
        print(" ",end=" ")
    print("*",end=" ")
    for f in range(j):
        print(" ",end=" ")
    if(j!=-1):
        print("*")
    x+=1
    j-=2
