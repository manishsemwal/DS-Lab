/*Dev C++*/
/*
Write C/C++ program to compute the k closest elements from a key value x
that belongs to the array A[n] of n data items. 
 
 Hint: 
1. PARTITION (described in QUICKSORT) the array A[n] around x as the 
pivot. 
2. For all elements to the left of x construct a max heap. 
3. For all elements to the right of x construct a min heap.
*/
#include <iostream>
#include <cmath>
using namespace std;

int partition(int a[], int l, int r){
    int x=a[l],i=l;
    for(int j=l+1;j<=r;j++){
        if(a[j]<=x){
            i++;
            int temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
    }
    int temp=a[l];
    a[l]=a[i];
    a[i]=temp;
    return i;
}

void maxHeapify(int a[], int i, int heapSize){
    int l=2*i+1;
    int r=2*i+2;
    int largest=i;
    if(l<heapSize && a[l]>a[largest]){
        largest=l;
    }
    if(r<heapSize && a[r]>a[largest]){
        largest=r;
    }
    if(largest!=i){
        int temp=a[largest];
        a[largest]=a[i];
        a[i]=temp;
        maxHeapify(a, largest, heapSize);
    }
}

void minHeapify(int a[], int i, int heapSize){
    int l=2*i+1;
    int r=2*i+2;
    int smallest=i;
    if(l<heapSize && a[l]<a[smallest]){
        smallest=l;
    }
    if(r<heapSize && a[r]<a[smallest]){
        smallest=r;
    }
    if(smallest!=i){
        int temp=a[smallest];
        a[smallest]=a[i];
        a[i]=temp;
        minHeapify(a, smallest, heapSize);
    }
}

void buildMaxHeap(int a[], int n){
    for(int i=(n/2)-1;i>=0;i--)
        maxHeapify(a, i, n);
}

void buildMinHeap(int a[], int n){
    for(int i=(n/2)-1;i>=0;i--)
        minHeapify(a, i, n);
}

int main() {
    int n,k,x;
    cout<<"Enter the size of the array:\n";
    cin>>n;
    cout<<"Enter "<<n<<" elements:\n";
    int *a = new int[n];
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<"Enter the value of k:\n";
    cin>>k;
    cout<<"Enter key value x:\n";
    cin>>x;
    
    for(int i=0;i<n;i++){
        if(a[i]==x){
            a[i]=a[0];
            a[0]=x;
            break;
        }
    }
    
    int index = partition(a,0,n-1);
    
    int lsize=index, rsize=n-index-1;
    int *left = new int[lsize];
    int *right = new int[rsize];
    
    for(int i=0;i<lsize;i++) left[i]=a[i];
    for(int i=0;i<rsize;i++) right[i]=a[i+index+1];
    
    buildMaxHeap(left, lsize);
    buildMinHeap(right, rsize);
    
    cout<<"\nThe "<<k<<" closet elements to "<<x<<" are:\n";
    for(int i=0;i<k;i++){
        if(abs(left[0]-x)<abs(right[0]-x)){
            cout<<left[0]<<" ";
            left[0]=left[lsize-1];
            lsize--;
            maxHeapify(left, 0, lsize);
        }
        else{
            cout<<right[0]<<" ";
            right[0]=right[rsize-1];
            rsize--;
            minHeapify(right, 0, rsize);
        }
    }
    
    delete[] a;
    delete[] left;
    delete[] right;
}
