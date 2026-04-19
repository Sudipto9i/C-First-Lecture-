
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

//2. DISTANCE FROM SOURCE (MOST IMPORTANT 🔥)
//💡 Question:

//👉 “Find shortest distance from source to all nodes using BFS”

//Expected Output:
//Node 1 → 0
//Node 2 → 1
//Node 3 → 2

//👉 They LOVE this question
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>G;///Adjacency List
vector<int>dis;
vector<bool>visited;

void BFS(int s){
    queue<int> Q;
    Q.push(s);
    visited[s]=true;
    dis[s]=0;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();

        for(int i=0;i<G[u].size();i++){
            int v = G[u][i];
            if(!visited[v]){
                visited[v]=true;
                dis[v]=dis[u]+1;///MAIN LOGIC
                Q.push(v);
            }
        }
    }
}
int main(){
    int node,edge;
    cin>>node>>edge;

    G.resize(node+1);
    dis.resize(node+1,-1);
    visited.resize(node+1,false);

    for(int i=0;i<edge;i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int source;
    cin>>source;

    BFS(source);

    cout<<"\nShortest distance from the source \n";
    for(int i=1;i<=node;i++){
        cout<<"Nodes "<<i<<"->"<<dis[i]<<endl;
    }
    return 0;
}

//3. SHORTEST PATH (SLIGHTLY ADVANCED)
//💡 Question:

//👉 “Find shortest path from source to destination”

//Trick:

//👉 Store parent array

//vector<int> parent(n+1, -1);
//parent[v] = u;

//Then backtrack:

//dest → parent → parent → source
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>G;
///Adjacency List
vector<int>dis,parent;
vector<bool>visited;
void BFS(int s){
    queue<int> Q;
    Q.push(s);
    visited[s]=true;
    dis[s]=0;
    parent[s]=-1;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(int i=0;i<G[u].size();i++){
            int v = G[u][i];
            if(!visited[v]){
                visited[v]=true;
                dis[v]=dis[u]+1;
                parent[v]=u;//Store Path
                Q.push(v);
            }
        }
    }
}
void printPath(int dest){
    if(dest==-1)return;

    printPath(parent[dest]);//Go to parent
    cout<<dest<<" ";//print while returning
}
int main(){
    int nodes,edges;
    cin>>nodes>>edges;

    G.resize(nodes+1);
    dis.resize(nodes+1,-1);
    parent.resize(nodes+1,-1);
    visited.resize(nodes+1,false);

    for(int i=0;i<edges;i++){
        int u , v ;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int source, dest;
    cin>>source>>dest;
    BFS(source);
    if(dis[dest]==-1){
        cout<<"No path exist\n";
    }else{
        cout<<"Shortest distance: "<<dis[dest]<<endl;
        cout<<"Path: ";
        printPath(dest);
    }
    return 0;
}

//4. CHECK CONNECTED GRAPH
//💡 Question:

//👉 “Check if graph is connected using BFS”

//Logic:
///Run BFS from 1 node
///If any node remains unvisited → NOT connected

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>G;///Adjacency List
vector<bool>visited;
void BFS(int s){
    queue<int> Q;
    Q.push(s);
    visited[s]=true;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(int i=0;i<G[u].size();i++){
            int v = G[u][i];
            if(!visited[v]){
                visited[v]=true;
                Q.push(v);
            }
        }
    }
}
int main(){
    int nodes,edges;
    cin>>nodes>>edges;
    G.resize(nodes+1);
    visited.resize(nodes+1,false);
    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    BFS(1);// start from node 1

    bool isConnected = true;

    for(int i=1 ;i<=nodes;i++){
        if(!visited[i]){
            isConnected = false;
            break;
        }
    }

    if(isConnected){
        cout<<"Graph is Connected\n";
    }else{
        cout<<"Graph is NOT Connected\n";
    }
    return 0;
}

//5. COUNT COMPONENTS (VERY COMMON)
//💡 Question:

//👉 “Find number of connected components”

//for(int i=1; i<=n; i++){
    //if(color[i] == -1){
        //BFS(i);
        //count++;
    //}
//}
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> G;
vector<bool>visited;
void BFS(int s){
    queue<int> Q;
    Q.push(s);
    visited[s]=true;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        for(int i=0;i<G[u].size();i++){
            int v = G[u][i];
            if(!visited[v]){
                visited[v]=true;
                Q.push(v);
            }
        }
    }
}
int main(){
    int node,edge;
    cin>>node>>edge;
    G.resize(node+1);
    visited.resize(node+1,false);
    for(int i=0;i<edge;i++){
        int u , v ;
        cin>>u>>v;
        G[u].resize(v);
        G[v].resize(u);
    }
    int count = 0;
    for(int i=0;i<=node;i++){
        if(!visited[i]){
            BFS(i);//explore one component
            count++;//increase count
        }
    }
    cout<<"Number of connected component: "<<count<<endl;
    return 0;
}
















