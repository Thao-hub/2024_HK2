#include <iostream>
#include <vector>

using namespace std;

const int n = 5;
vector<int> graph[n] = {
    {1, 3},
    {0, 2, 3, 4},
    {1, 4},
    {0, 1, 4},
    {1, 2, 3}
};

vector<int> path(n, -1);
vector<bool> visited(n, false);

bool Tim_Chu_Trinh_Hamilton(int pos, int count) {
    if (count == n) {
        for (int neighbor : graph[path[count - 1]]) {
            if (neighbor == path[0]) return true;
        }
        return false;
    }

    for (int neighbor : graph[path[count - 1]]) {
        if (!visited[neighbor]) {
            path[count] = neighbor;
            visited[neighbor] = true;
            
            if (Tim_Chu_Trinh_Hamilton(neighbor, count + 1)) return true;
            
            visited[neighbor] = false;
        }
    }
    return false;
}

int main() {
    path[0] = 0;
    visited[0] = true;

    if (Tim_Chu_Trinh_Hamilton(0, 1)) {
        cout << "Chu trinh Hamilton can tim la: ";
        for (int i = 0; i < n; i++) cout << path[i] << " ";
        cout << path[0] << endl;
    } else {
        cout << "Khong co chu trinh Hamilton\n";
    }

    return 0;
}

