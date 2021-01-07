/*Dev C++*/
/*Create a binary tree having preorder threads. WAnotherP to traverse the tree in preorder using those threads*/

#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <cstdlib>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
    bool flag;
};

struct node * makeTree(vector<int> v, vector<struct node *> ad){
    if(v[0]==9999) return NULL;

    ad[0] = (struct node *)malloc(sizeof(struct node));
    ad[0]->data=v[0];
    ad[0]->left=ad[0]->right=NULL;
    ad[0]->flag=0;
    for(int i=0;i<v.size();i++){
        if(v[i]!=9999){
            ad[i] = (struct node *)malloc(sizeof(struct node));
            ad[i]->data=v[i];
            ad[i]->left=ad[i]->right=NULL;
            ad[i]->flag=0;
            if(i%2==1){
                ad[(i-1)/2]->left=ad[i];
            }
            else{
                ad[(i-1)/2]->right=ad[i];
            }
        }
    }
    return ad[0];
}

void createThreadedTree(struct node *t, queue<struct node *> *q){
    if(t==NULL) return;
    
    q->pop();
    if(t->left!=NULL) createThreadedTree(t->left,q);
    if(t->right!=NULL) createThreadedTree(t->right,q);
    else{
        t->right=q->front();
        t->flag=true;
    }
}

void fillQueue(struct node *t, queue<struct node *> *q){
    if(t==NULL) return;
    
    q->push(t);
    if(t->left!=NULL) fillQueue(t->left, q);
    if(t->right!=NULL) fillQueue(t->right, q);
    
}

void threadIt(struct node * t){
    queue<struct node *> q;
    fillQueue(t, &q);
    createThreadedTree(t, &q);
}

void preOrderThreaded(struct node * t){
    if(t==NULL) return;
    
    struct node *node=t;
    while(node!=NULL){
        cout<<node->data<<" ";
        if(node->left!=NULL) node=node->left;
        else node=node->right;
    }
}

int main(){
    cout<<"Note: Input the values (integer) of tree level wise and enter '9999' for 'NULL'\n";
    int nl,x;
    cout<<"Enter the no. of levels of the binary tree :\n";
    cin>>nl;
    vector<int> v;
    vector<struct node *> ad;
    for(int i=1;i<=nl;i++){
        cout<<"Enter the elements of level "<<i<<" :\n";
        for(int j=0;j<pow(2,i-1);j++){
            cin>>x;
            v.push_back(x);
            ad.push_back(NULL);
        }
    }

    struct node *t = makeTree(v, ad);
    threadIt(t);
    cout<<"Preorder traversal of threaded binary tree is : ";
    preOrderThreaded(t);
}
