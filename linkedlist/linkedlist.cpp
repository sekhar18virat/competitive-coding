

#include <iostream>

using namespace std;

class node{
public:
    int data;
    node * next;
};

class linkedlist{
    node * first;
public:
    linkedlist(){first=NULL ;}
    linkedlist(int a[],int n);
    
    void disp();
    void insert(int index,int x);
    int count();
    void del(int index);
    void reverlist();
};

linkedlist::linkedlist(int a[],int n){
    node *last,*temp;
    int i;
    first=new node;
    first->next=NULL;
    first->data=a[0];
    last=first;
    for(i=1;i<n;i++){
        temp=new node;
        temp->data=a[i];
        last->next=temp;
        last=temp;
    }
    
}
void linkedlist::disp(){
    node *p;
    p=new node;
    p=first;
    while(p){
        cout<<p->data;
        p=p->next;
        cout<<"\t";
    }
    cout<<"\n";
}

int linkedlist::count(){
    node *p;
    p=new node;
    p=first;
    int i=0;
    while(p){
        i++;
        p=p->next;
    }
    return i;
    
}

void linkedlist::insert(int index,int x){
    node *p,*t;
    p=new node;
    t=first;
    p->data=x;
    p->next=NULL;
    int i=0;
    if(index<0){
        return ;
    }
    else{
        if(index==0){
            p->next=t;
            first=p;
        }
        else{
            for(i=1;i<index-1;i++){
                t=t->next;
            }
            p->next=t->next;
            t->next=p;
        }
        
    }
}


void linkedlist::reverlist(){
    node *p,*q,*r;
    p=first;
    while(p!=NULL){
        r=p->next;
        p->next=q;
        q=p;
        p=r;
    }
    first=q;
}

void linkedlist::del(int index){
    int i=0;
    node *p,*q;
    p=first;
    if(index==0){
        first=p->next;
        p->next=NULL;
        delete p;
    }
    else{
        for(i=0;i<index-1;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        delete p;
        
    }
}
int main()
{
    int z;
    int a[5]={1,2,3,4,5};
    linkedlist l(a,5);
    l.disp();
    l.insert(2,3);
    l.disp();
    l.delete(3);
    l.reverlist();
    l.disp();
    

    return 0;
}
