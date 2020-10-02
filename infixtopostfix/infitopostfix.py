from collections import deque
def isoperand(n):
    if(n=="+" or n=="-" or n=="*" or n=="/"):
        return 0
    else:
        return 1
def check(c):
    if(c=="+" or c=="-"):
        return 1
    if(c=="*" or c=="/"):
        return 2
def infixtopostfix(infix):
    stack=deque()
    post=""
    j=-1
    for i in infix:
        if(isoperand(i)):
            post=post+i
        else:
            if(stack):
                if(check(i)>check(stack[j])):
                    stack.append(i)
                    j+=1
                else:
                    while(j>=0 and check(stack[j])>=check(i) ):
                        post+=stack.pop()
                        j-=1
                    stack.append(i)
            else:
                stack.append(i)
                j+=1
                
                            
    if(stack):     
        for i in range(len(stack)):
            post+=stack.pop()
    print(post)
n=input()
infixtopostfix(n)