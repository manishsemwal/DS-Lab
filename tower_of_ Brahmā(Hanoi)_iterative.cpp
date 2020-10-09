/* Dev c++ */

#include <iostream>
#include <cmath>
using namespace std;

class stack{
    int top=-1;
    int *s;
    public:
    stack(int size){
        s = new int[size];
    }
    void init(int size){
         for(int i=0;i<size;i++){
            s[i]=size-i;
        }
        top=size-1;
    }
    
    void push(int x){
        s[++top]=x;
    }
    
    int pop(){
        return s[top--]; 
    }
    
    bool isEmpty(){
        if(top==-1) return true;
        return false;
    }
    
    void move(stack *z, char c1, char c2){
        if(!isEmpty() && !z->isEmpty()){
            if(s[top] < z->s[z->top]){
                int x = pop();
                cout<<"Move the top disk"<<" from pole "<<c1<<" to pole "<<c2<<endl;
                z->push(x);
            }
            else{
                int x = z->pop();
                cout<<"Move the top disk"<<" from pole "<<c2<<" to pole "<<c1<<endl;
                push(x);
            }
        }
        else if(isEmpty()){
            int x = z->pop();
            cout<<"Move the top disk"<<" from pole "<<c2<<" to pole "<<c1<<endl;
            push(x);
        }
        else{
            int x = pop();
            cout<<"Move the top disk"<<" from pole "<<c1<<" to pole "<<c2<<endl;
            z->push(x);
        }
    }
    
};

int main() {
    cout<<"Considered 3 poles Source, Auxilliary and Destination are represented by S,A and D respectively\n\n";
    
    cout<<"Enter the no. of disks : ";
    int n;
    cin>>n;
    
    stack s(n),a(n),d(n);
    s.init(n);
    
    long long moves = pow(2,n) - 1;
    if(n%2==1){
        for(long long i=1 ; i<=moves ; i++){
            if(i%3==1){
                s.move(&d, 'S', 'D');
            }
            else if(i%3==2){
                s.move(&a, 'S', 'A');
            }
            else{ // i%3==0
                a.move(&d, 'A', 'D');
            }
        }
    }
    else{
        for(long long i=1 ; i<=moves ; i++){
            if(i%3==1){
                s.move(&a, 'S', 'A');
            }
            else if(i%3==2){
                s.move(&d, 'S', 'D');
            }
            else{ // i%3==0
                a.move(&d, 'A', 'D'); //equivalent to its flipped version
            }
        }
    }
    
}
