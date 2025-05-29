#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

#define V 9  

typedef pair<int, int> iPair;

void primMST(vector<vector<int>> &graph) {
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    int src = 0; 

    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    pq.push({0, src});
    key[src] = 0;
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    cout << "Cay khung nho nhat la: \n";
    cout << "T = {";
    int totalWeight = 0;
    bool first = true;

    for (int i = 1; i < V; i++) {
        if (!first) cout << ", ";
        cout << "(" << parent[i] << ", " << i << ")";
        first = false;
        totalWeight += graph[i][parent[i]];
    }
    cout << "}\n";
    cout << "Tong trong so cua cay khung nho nhat: " << totalWeight << "\n";
}

int main() {
    vector<vector<int>> graph = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 11, 0, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    primMST(graph);
    return 0;
}

