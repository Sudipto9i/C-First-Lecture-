#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

struct Edge {
    int destination, weight;
};

vector<int> parent;

vector<int> dijkstra(const vector<vector<Edge>>& graph, int source, int totalNodes) {
    vector<int> dist(totalNodes, INT_MAX);
    parent.assign(totalNodes, -1);
    dist[source] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (const Edge& edge : graph[u]) {
            int v = edge.destination, w = edge.weight;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

string reconstructPath(int target) {
    vector<int> path;
    for (int cur = target; cur != -1; cur = parent[cur])
        path.push_back(cur);
    reverse(path.begin(), path.end());
    string result = "";
    for (int i = 0; i < (int)path.size(); i++) {
        result += to_string(path[i]);
        if (i < (int)path.size() - 1) result += " -> ";
    }
    return result;
}

int main() {
    int N, E;

    cout << "Enter number of customers: ";
    cin >> N;

    cout << "Enter number of roads: ";
    cin >> E;

    vector<vector<Edge>> graph(N + 1);

    cout << "Enter road distances (u  v  distance):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<int> dist = dijkstra(graph, 0, N + 1);

    cout << "\n========== Delivery Route Results ==========" << endl;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == INT_MAX)
            cout << "Customer " << i << ": Not reachable" << endl;
        else
            cout << "Customer " << i
                 << ": Minimum Distance = " << dist[i]
                 << ", Path = " << reconstructPath(i) << endl;
    }
    cout << "============================================" << endl;

    return 0;
}
