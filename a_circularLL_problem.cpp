/*
Implement Josephus Problem using circular linked list. Let n be the number of persons standing in a circle facing the center, 
let k be a skip number agreed upon in advance and let A be the person who begins the process. On each iteration, 
x will kill kth person on the left, where x begins with A and is reset to be the person on the left of the person killed each time. 
For example if n=10 (A, B, C, D, E, F, G, H, I, J) and k=3, then A kills D, E kills H, I kills B, C kills G, etc.. 
Your program will accept n and k as input from the user. 
Output the order of execution and the number of links traversed till the program terminates. 
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int linkCount=0;

struct node{
    int data;
    struct node * next;
};

struct node * createCLL(int n){ // returns head of a circular linked list that has n-nodes
    int m=n;
    struct node *head=NULL;
    struct node *curr=NULL;
    while(n--){
        struct node *p = (struct node *)malloc(sizeof(struct node));
        p->data=m-n;
        p->next=NULL;
        if(head==NULL){
            head=p;
            curr=p;
        }
        else{
            curr->next=p;
            curr=p;
        }
    }
    curr->next=head;
    return head;
}

struct node * kill(struct node *head, int n, int k){//a node kills another node according to current no. of survivers and value of k
    if(n>k){
        cout<<head->data<<" kills ";
        linkCount+=(k+1);
        k--;
        struct node * prev = head; 
        head=head->next;
        while(k--){
            prev=head;
            head=head->next;
        }
        cout<<head->data<<"\n";
        prev->next=head->next;
        free(head);
        return prev->next;
    }
    else{//n<=k
        cout<<head->data<<" kills ";
        linkCount+=((k%n)+1);
        k--;
        struct node * prev = head; 
        head=head->next;
        while(k--){
            prev=head;
            head=head->next;
        }
        cout<<head->data<<"\n";
        prev->next=head->next;
        free(head);
        
        return prev->next;
    }
}

int main() {
    int n,k,nodeCount;
    cout<<"Enter the values of n and k :\n";
    cin>>n>>k;
    nodeCount=n;
    struct node *head = createCLL(n);
    while(nodeCount>1){
        head=kill(head,n,k);
        n--;
        nodeCount--;
    }
    cout<<head->data<<" survives\n";
    cout<<"Total no. of links traversed : "<<linkCount;
}
