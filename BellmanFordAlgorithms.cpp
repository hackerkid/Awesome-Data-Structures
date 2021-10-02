#include<bits/stdc++.h>
using namespace std;

struct Node{
    int u;
    int v;
    int wt;
    Node(int x,int y,int weight){
        u=x;
        v=y;
        wt=weight;
    }
};      
int main(){
    int m,n;
    cin>>m>>n;

    vector<Node> edges;
    for(int i=0;i<m;i++){
        int u, v, wt;
        cin>>u>>v>>wt;
        edges.push_back(Node(u,v,wt));
    }

    int dis[n];
    for(int i=0;i<n;i++){
        dis[i]=1e9;
    }
    int src=0;
    dis[src]=0;

    for(int i=0;i<n-1;i++){
     for(auto edge:edges){
        if(dis[edge.u]+edge.wt<dis[edge.v]){
           dis[edge.v]=dis[edge.u]+edge.wt; 
        }
    }
    }
    
    int flag=0;
    for(auto edge:edges){
        if(dis[edge.u]+edge.wt<dis[edge.v]){
           cout<<"Negative Cycle is present";
           flag=1;
           break;
        }
    }

    if(flag==0){
        for(int i=0;i<n;i++){
            cout<<i<<" "<<dis[i]<<endl;
        }
    }

    return 0;
}