/*  Dev C++  */

#include <iostream>
#define size 3
using namespace std;

class stack{
    int top=-1;
    int s[size];
    public:
        void push(int x){
            if(top==size-1){
                cout<<"Queue Overflow\n";
                return;
            }
            s[++top]=x;
            cout<<x<<" enQueued\n";
        }
        int pop(){
            return s[top--];
        }
        bool isEmpty(){
            return top==-1 ? true : false ;
        }
        void print1(){
            int t=0;
            while(t<=top) cout<<s[top]<<" ";
        }
        void print2(){
            int t=top;
            while(t>-1) cout<<s[t--]<<" ";
        }
};

class queue{
    public:
    void enqueue(stack *s1, int x){
        s1->push(x);
    }
    
    void dequeue(stack *s1 ,stack *s2){
        if(s2->isEmpty()){
            if(s1->isEmpty()){
                cout<<"Queue is empty can't deQueue\n";
                return;
            }else{
                while(!s1->isEmpty()){
                    s2->push(s1->pop());
                }
                cout<<s2->pop()<<" dequeued\n";
                return;
            }
        }
        cout<<s2->pop()<<" dequeued\n";
    }
    void print(stack *s1, stack *s2){
        cout<<"Currently Queue is : ";
        s2->print2();
        s1->print1();
        cout<<endl;
    }
};

int main() {
    stack s1,s2;
    queue q;
    cout<<"Note : Currently, the stacks used to implement queue has size '"<<size<<"', so please change 'size' in second line of the code if you want to enQueque larger number of integers.\n";
    while(1){
        cout<<"\nMenu:\n";
        cout<<"1.enQueue()\n";
        cout<<"2.deQueue()\n";
        cout<<"3.Print Queue\n";
        cout<<"4.Exit\n";
        cout<<"Enter a choice : ";
        int n;
        cin>>n;
        switch(n){
            case 1:
                {
                int x;
                cin>>x;
                q.enqueue(&s1, x);
                break;
                }
            case 2:
                q.dequeue(&s1, &s2);
                break;
            case 3:
                q.print(&s1, &s2);
                break;
            case 4:
                exit(1);
            default:
                cout<<"Please enter a valid choice\n";
        }
    }
}
