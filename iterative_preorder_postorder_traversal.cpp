/*Dev C++*/
/*Non-recursive preorder and postorder traversal of a binary tree*/
#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <cstdlib>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node* right;
};

struct node * makeTree(vector<int> v, vector<struct node *> ad){
    if(v[0]==9999) return NULL;
    
    ad[0] = (struct node *)malloc(sizeof(struct node));
    ad[0]->data=v[0];
    ad[0]->left=ad[0]->right=NULL;
    for(int i=0;i<v.size();i++){
        if(v[i]!=9999){
            ad[i] = (struct node *)malloc(sizeof(struct node));
            ad[i]->data=v[i];
            ad[i]->left=ad[i]->right=NULL;
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

void preOrderTraversal(struct node * t){
    if(t==NULL) return;
    
    stack<struct node *> s;
    s.push(t);
    while(!s.empty()){
        struct node *x = s.top();
        s.pop();
        cout<<x->data<<" ";
        
        if(x->right!=NULL) s.push(x->right);
        if(x->left!=NULL) s.push(x->left);
    }
}

void postOrderTraversal(struct node * t){
    if(t==NULL) return;
    
    stack<struct node *> s1,s2;
    
    s1.push(t);
    
    while(!s1.empty()){
        struct node *x=s1.top();
        s1.pop();
        s2.push(x);
        
        if(x->left!=NULL) s1.push(x->left);
        if(x->right!=NULL) s1.push(x->right);
    }
    
    while(!s2.empty()){
        cout<<(s2.top())->data<<" ";
        s2.pop();
    }
}

int main(){
    cout<<"Note: Input the values (integer) of tree, level wise and enter '9999' for 'NULL'\n";
    int nl,x;
    cout<<"Enter the no. of levels of the binary tree :\n";
    cin>>nl;
    vector<int> v;
    vector<struct node *> ad;
    for(int i=1;i<=nl;i++){
        cout<<"Enter "<<pow(2,i-1)<<" element(s) of level "<<i<<" :\n";
        for(int j=0;j<pow(2,i-1);j++){
            cin>>x;
            v.push_back(x);
            ad.push_back(NULL);
        }
    }
    
    struct node *t = makeTree(v, ad);
    cout<<"Preorder traversal : ";
    preOrderTraversal(t);
    cout<<endl;
    cout<<"Postorder traversal : ";
    postOrderTraversal(t);
}
