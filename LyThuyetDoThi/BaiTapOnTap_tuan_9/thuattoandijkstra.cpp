#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define V 9  

void dijkstra(vector<vector<int>> &graph, int src) {
    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visited[v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Khoang cach ngan nhat tu dinh " << src << " den cac dinh khac:\n";
    for (int i = 0; i < V; i++)
        cout << "Ðinh " << i << " - Khoang cach: " << dist[i] << endl;
}

int main() {
    vector<vector<int>> graph = {
        {0, 4, 0, 0, 0, 0, 8, 0, 0},
        {4, 0, 8, 0, 0, 0, 11, 0, 0},
        {0, 8, 0, 7, 0, 0, 0, 2, 0},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 0, 14, 10, 0, 2, 0, 0},
        {8, 11, 0, 0, 0, 2, 0, 1, 6},
        {0, 0, 2, 0, 0, 0, 1, 0, 7},
        {0, 0, 0, 0, 0, 0, 6, 7, 0}
    };

    int start = 0;  
    dijkstra(graph, start);

    return 0;
}

