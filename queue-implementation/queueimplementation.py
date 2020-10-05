#include <iostream>

using namespace std;
class queue{
    private:
            int front;
            int rear;
            int size;
            int *q;
            
    public:
            queue(){front=rear=-1;q=new int[10];}
            queue(int x){front=rear=-1;this->size=x;q=new int[this->size];}
            int dequeue();
            void enqueue(int x);
            void display();
};

void queue::enqueue(int x){
    if(rear==size-1){
        cout<<"full queue";
    }
    else{
        rear++;
        q[rear]=x;
    }
    
}

int queue::dequeue(){
    int x=-1;
    if(front==rear){
        cout<<"empty queue";
    }
    else{

        x=q[front+1];
        front++;
        return(x);
    }
}

void queue::display(){
    for(int i=front+1;i<=rear;i++){
        cout<<q[i];
        cout<<"\n";
    }
}
int main()
{
    queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();
    cout<<q.dequeue();

    return 0;
}