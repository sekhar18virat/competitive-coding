#include <iostream>

using namespace std;
struct ele{
    int i;
    int j;
    int x;
};
struct sparse{
    int m;
    int n;
    int num;
    struct ele *e;
};

void create(struct sparse *s){
    cin>>(s->m);
    cin>>(s->n);
    cin>>(s->num);
    s->e=new ele[s->num];
    for(int i=1;i<=(s->num);i++){
        cin>>(s->e[i].i);
        cin>>(s->e[i].j);
        cin>>(s->e[i].x);
    }
}
void display(struct sparse *s){
    int k=1;
    for(int i=1;i<=(s->m);i++){
        for(int j=1;j<=(s->n);j++){
            if(i==s->e[k].i && j==s->e[k].j){
                cout<<s->e[k++].x;
                cout<<"\t";
            }
            else{
                cout<<"0";
                cout<<"\t";
            }
        }
        cout<<"\n";
    }
}
int main()
{
    cout<<"Hello World";
    struct sparse s;
    create(&s);
    display(&s);

    return 0;
}