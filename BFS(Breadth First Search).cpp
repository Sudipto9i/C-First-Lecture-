//1. BASIC BFS IMPLEMENTATION (VERY COMMON)
//💡 Question:

//👉 “Write a program to perform BFS traversal from a given source.”

//What you must do:
//Take input
//Build graph
//Print traversal OR distance.
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>G;//G-->the adjacency list.
//G[u] is a list of all neighbours of node u.
vector<int> dis;//stores shortest distance from the source to each node.
vector<bool>visited;//tracks whether a node has been put in the queue already(so we don't repeat)
void BFS(int s){
    queue<int> Q;
    Q.push(s);//push the source s into the queue
    visited[s]=true;//Mark it visited
    dis[s]=0;//Set distance to 0.
    while(!Q.empty()){
        int u = Q.front();//We take the front node out(FIFO order)
        Q.pop();
        cout<<u<<" ";//Traversal print
        for(int i=0;i<G[u].size();i++){
            int v = G[u][i];
            if(!visited[v]){//If v hasn't been visited.
                visited[v]=true;
                dis[v]=dis[u]+1;
                Q.push(v);
            }
        }
    }
}
int main(){
    int nodes , edges;
    cin>>nodes>>edges;
    G.resize(nodes+1);
    dis.resize(nodes+1,-1);
    visited.resize(nodes+1,false);
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);//undirected graph
    }
    int source;
    cin>>source;
    cout<<"BFS Traversal: ";
    BFS(source);
    cout<<"\nDistance from source: \n";
    for(int i=1;i<=nodes;i++){
        cout<<"Nodes "<<i<<"->"<<dis[i]<<endl;
    }
    return 0;
}





























