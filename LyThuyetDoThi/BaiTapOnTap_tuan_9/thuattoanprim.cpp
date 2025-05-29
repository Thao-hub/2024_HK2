#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define V 9

int minKey(vector<int> &key, vector<bool> &mstSet) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void primMST(vector<vector<int>> &graph) {
    vector<int> parent(V);
    vector<int> key(V, INT_MAX);
    vector<bool> mstSet(V, false);

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    cout << "Cây khung nho nhat (MST) gom cac canh:\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \tTrong so: " << graph[i][parent[i]] << endl;
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

    primMST(graph);

    return 0;
}

