#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> G;
vector<int> dis;
vector<bool> visited;

void dijkstra(int s){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;

    dis[s] = 0;
    Q.push({0, s});

    while(!Q.empty()){
        int u = Q.top().second;
        Q.pop();

        if(visited[u]) continue;
        visited[u] = true;

        for(int i=0;i<G[u].size();i++){
            int v = G[u][i].first;
            int w = G[u][i].second;

            if(dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;
                Q.push({dis[v], v});
            }
        }
    }
}

int main(){
    int nodes, edges;
    cin>>nodes>>edges;

    G.resize(nodes+1);
    dis.resize(nodes+1, INT_MAX);
    visited.resize(nodes+1, false);

    for(int i=0;i<edges;i++){
        int u,v,w;
        cin>>u>>v>>w;

        G[u].push_back({v,w});
        G[v].push_back({u,w}); // remove if directed
    }

    int source;
    cin>>source;

    dijkstra(source);

    cout<<"Shortest Distance:\n";
    for(int i=1;i<=nodes;i++){
        cout<<"Node "<<i<<" -> "<<dis[i]<<endl;
    }

    return 0;
}
