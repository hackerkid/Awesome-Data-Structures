#include<bits/stdc++.h>
using namespace std;

void dfs(int src,stack<int> &st,bool visited[],vector<int> graph[]){   // dfs call for topological order
    visited[src]=true;

    for(auto nbr: graph[src]){
        if(visited[nbr]==false){
            dfs(nbr,st,visited,graph);
        }
    }
    st.push(src);
}

void redfs(int src,bool visited[],vector<int> transpose[]){      // dfs call on transpose 
    cout<<src<<" ";
    visited[src]=true;

    for(auto nbr: transpose[src]){
        if(visited[nbr]==false){
            redfs(nbr,visited,transpose);
        }
    }
}
int main(){
    int edge,vertex;
    cin>>edge>>vertex;

    vector<int> graph[vertex];
    
    for(int i=0;i<edge;i++){
        int u,v;
        cin>>u>>v;

        graph[u].push_back(v);
    }
    
    stack<int> st;
    bool visited[vertex];
    for(int i=0;i<vertex;i++){
        visited[i]=false;
    }

    for(int i=0;i<vertex;i++){          // 1st step topological order( order of finishing time for vertex)
        if(visited[i]==false){
            dfs(i,st,visited,graph);
        }
    }

    vector<int> transpose[vertex];
    for(int i=0;i<vertex;i++){                 // 2nd step make the transpose of graph
        visited[i]=false;
        for(auto nbr: graph[i]){
            transpose[nbr].push_back(i);
        }
    }

    while(!st.empty()){
        int node=st.top();        // 3rd step dfs call on transpose graph with topological order
        st.pop();

        if(visited[node]==false){
            cout<<"SCC: ";
            redfs(node,visited,transpose);
            cout<<endl;
        }
    }

    return 0;
}

