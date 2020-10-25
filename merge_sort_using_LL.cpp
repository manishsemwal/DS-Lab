/* Dev C++ */
/* S.C = O(n), Auxiliary Space = O(1) ; T.C = O(nlogn) */
#include <iostream>
#include <cstdlib>
using namespace std;

struct node{// linked list node
  int data;
  struct node * next;
};

void print(struct node * head){// printing current linked list
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

void split(struct node * head, struct node ** start1, struct node ** start2){
    struct node * fast;
    struct node * slow;
    slow=head;
    fast=head->next;
    
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
    }
    *start1=head;
    *start2=slow->next;
    slow->next=NULL;
}

struct node * merge(struct node * start1, struct node * start2){
    struct node * head=NULL;
    if(start1==NULL) return start2;
    else if(start2==NULL) return start1;
    
    if(start1->data<=start2->data){
        head=start1;
        head->next = merge(start1->next,start2);
    }
    else{
        head=start2;
        head->next = merge(start1,start2->next);
    }
    return head;
}

void mergeSort(struct node ** headOriginal){
    
    struct node *head = *headOriginal;
    
    if(head==NULL || head->next==NULL) return;
    
    struct node * start1;
    struct node * start2;
    split(head, &start1, &start2);
    mergeSort(&start1);
    mergeSort(&start2);
    *headOriginal = merge(start1,start2);
}

int main() {
    int n,size,e;
    cout<<"Enter the no. of elements to be sorted :\n";
    cin>>n;
    size=n;
    struct node *head;
    struct node *curr;
    while(n--){
        cout<<"Enter element "<<size-n<<" : ";
        if(size-n==1){
            head = (struct node *)malloc(sizeof(struct node));
            cin>>e;
            head->data=e;
            head->next=NULL;
            curr=head;
        }
        else{
            curr->next = (struct node *)malloc(sizeof(struct node));
            curr=curr->next;
            curr->next=NULL;
            cin>>e;
            curr->data=e;
        }
    }
    cout<<"List before sorting :\n";
    print(head);
    
    mergeSort(&head);
    
    cout<<"\nList after sorting :\n";
    print(head);
    
}
