from collections import deque
def balanced(n):
    l=deque()
    j=-1
    for i in range(len(n)):
        if(n[i]=="(" or n[i]=="{" or n[i]=="["):
            l.append(n[i])
            j+=1
        elif(n[i]==")" or n[i]=="}" or n[i]=="]"):
            if(l):
                if(l[j]=="(" and n[i]==")"):
                    l.pop()
                    j-=1
                elif(l[j]=="{" and n[i]=="}"):
                    l.pop()
                    j-=1
                elif(l[j]=="[" and n[i]=="]"):
                    l.pop()
                    j-=1
                else:
                    return("not balanced")
                
            else:
                return("not balanced")
        else:
            pass
    if(l):
        return"not balanced"
    else:
        return" balanced"
n=input()
print(balanced(n))