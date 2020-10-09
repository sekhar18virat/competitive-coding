#include <iostream>

using namespace std;
class Node{
    public:
            int data;
            Node *left;
            Node *right;
};
class queue{
    private:
            int front;
            int rear;
            int size;
            Node **q;
            
    public:
            queue(){front=rear=-1;q=new Node*[10];}
            queue(int x){front=rear=-1;this->size=x;q=new Node*[this->size];}
            Node * dequeue();
            void enqueue(Node *x);
            void display();
            int isempty(){return front==rear;}
};

void queue::enqueue(Node *x){
    if(rear==size-1){
        cout<<"full queue";
    }
    else{
        rear++;
        q[rear]=x;
    }
    
}

Node * queue::dequeue(){
    Node * x=NULL;
    if(front==rear){
        cout<<"empty queue";
    }
    else{

        x=q[front+1];
        front++;
        return(x);
    }
}

class Tree{
    public:
            Node *root;
            Tree(){root=NULL;}
            int Height(Node *root);
            void levelorder(Node *root);
            void inorder(Node *root);
            void preorder(Node *root);
            void postorder(Node *root);
            void createTree();
            int countnoofnodes(Node *root);
            int leafnodes(Node *root);
            int degree1nodes(Node *root);
            int degree2nodes(Node *root);
};

void Tree::createTree(){
    Node *p,*t;
    int x;
    queue q(100);
    cout<<"enter root value ";
    cin>>x;
    root=new Node;
    root->data=x;
    root->left=root->right=NULL;
    q.enqueue(root);
    while(!q.isempty()){
        p=q.dequeue();
        cout<<"enter left child of ";
        cout<<p->data;
        cout<<" ";
        cin>>x;
        if(x!=-1){
            t=new Node;
            t->data=x;
            t->left=t->right=NULL;
            p->left=t;
            q.enqueue(t);
        }
        cout<<"enter right child of ";
        cout<<p->data;
        cout<<" ";
        cin>>x;
        if(x!=-1){
            t=new Node;
            t->data=x;
            t->left=t->right=NULL;
            p->right=t;
            q.enqueue(t);
        }
    }
}

void Tree::preorder(Node *p){
    if(p){
        cout<<p->data;
        cout<<" ";
        preorder(p->left);
        preorder(p->right);
    }
}

void Tree::inorder(Node *p){
    if(p){
        inorder(p->left);
        cout<<p->data;
        cout<<" ";
        inorder(p->right);
    }
}

void Tree::postorder(Node *p){
    if(p){
        postorder(p->left);
        postorder(p->right);
        cout<<p->data;
        cout<<" ";
    }
}

void Tree::levelorder(Node *p){
    queue q(100);
    q.enqueue(p);
    cout<<p->data;
    cout<<" ";
    while(!q.isempty()){
        p=q.dequeue();
        if(p->left){
            cout<<p->left->data;
            cout<<" ";
            q.enqueue(p->left);
        }
        if(p->right){
            cout<<p->right->data;
            cout<<" ";
            q.enqueue(p->right);
        }
    }
    
}

int Tree::Height(Node *p){
    int x=0,y=0;
    if(p==0){
        return 0;
    }
    x=Height(p->left);
    y=Height(p->right);
    if(x>y){
        return x+1;
    }
    else
    return y+1;
}

int Tree:: countnoofnodes(Node *p){
    int x,y;
    if(p){
        return countnoofnodes(p->left)+countnoofnodes(p->right)+1;
        
    }
    return 0;
}


int Tree:: leafnodes(Node *p){
    int x,y;
    if(p){
        x=leafnodes(p->left);
        y=leafnodes(p->right);
        if(p->left==NULL and p->right==NULL){
            return x+y+1;
        }
        else{
            return x+y;
        }
    }
    return 0;
    
}

int Tree::degree1nodes(Node *p){
    int x,y;
    if(p){
        x=degree1nodes(p->left);
        y=degree1nodes(p->right);
        if((p->left==NULL and p->right!=NULL) or (p->left!=NULL and p->right==NULL)){
            return x+y+1;
        }
        else{
            return x+y;
        }
    }
    return 0;
    
}

int Tree::degree2nodes(Node *p){
    int x,y;
    if(p){
        x=degree2nodes(p->left);
        y=degree2nodes(p->right);
        if(p->left!=NULL and p->right!=NULL){
            return x+y+1;
        }
        else{
            return x+y;
        }
    }
    return 0;
    
}


int main()
{
    Tree t;
    t.createTree();
    cout<<"the preorder traversal of the given tree is ";
    t.preorder(t.root);
    cout<<"\n";
    cout<<"the postorder traversal of the given tree is ";
    t.postorder(t.root);
    cout<<"\n";
    cout<<"the inorder traversal of the given tree is ";
    t.inorder(t.root);
    cout<<"\n";
    cout<<"the levelorder traversal of the given tree is ";
    t.levelorder(t.root);
    cout<<"\n";
    cout<<"the height of tree is ";
    cout<<t.Height(t.root);
    cout<<"\n";
    
    cout<<"No.of nodes in tree ";
    cout<<t.countnoofnodes(t.root);
    cout<<"\n";
    cout<<"No.of  leaf nodes in tree ";
    cout<<t.leafnodes(t.root);
    cout<<"\n";
     cout<<"No.of nodesof degree 1 in tree ";
    cout<<t.degree1nodes(t.root);
    cout<<"\n";
     cout<<"No.of nodes of degree 2 in tree ";
    cout<<t.degree2nodes(t.root);
    cout<<"\n";
    
    return 0;
}
