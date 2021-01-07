/*Dev C++*/
/*
Write an efficient C/C++ program that inputs a DAG (directed acyclic graph) 
G = (V, E) and an ordering a of the vertices of G. The program returns TRUE 
if a is a topological sort of G or FALSE if a is not a topological sort of G. 
(Assume vertices are numbered from 1..n where |V| = n)
*/
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,e,u,v;
    cout<<"NOTE: The vertices are named in natural numbers i.e. 1 to n\n\n";
    cout<<"Enter the no. of vertices :\n";
    cin>>n;
    vector< vector<int> > g(n+1); //graph g
    bool *visited = new bool[n+1]; //visited array keeps track of the nodes that has been visited in the toposort
    for(int i=1;i<=n;i++) visited[i]=false;
    cout<<"Enter the no. of edges :\n";
    cin>>e;
    cout<<"Enter "<<e<<" edge pairs:\n";
    for(int i=1;i<=e;i++){ //entering edges in reverse direction to store i/p graph's dependency graph
        cin>>u>>v;
        g[v].push_back(u);
    }
    int x,flag=0;
    int *a = new int[n];
    cout<<"Enter the ordering 'a':\n";
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        x=a[i];
        if(g[x].size()==0){ // if current vertex doesn't depend on any other vertex, to be visited in toposort
            visited[x]=true;
            continue;
        }
        for(int j=0;j<g[x].size();j++){ //checking if all vertices on which current vertex depends have already been visited
            if(visited[g[x][j]]!=1){
                cout<<"FALSE";
                delete[] visited;
                delete[] a;
                return 0;
            }
        }
        visited[x]=true;
    }
    
    cout<<"TRUE";
    delete[] visited;
    delete[] a;
    return 0;
    
}
