#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class DoThi {
    int soDinh; // So dinh
    vector<vector<int>> dsKe; // Danh sach ke

public:
    DoThi(int soDinh);
    void themCanh(int v, int w);
    void duyetBFS(int s);
    void duyetDFS(int s);
    void DFSHoTro(int v, vector<bool>& daTham);
};

DoThi::DoThi(int soDinh) {
    this->soDinh = soDinh;
    dsKe.resize(soDinh);
}

void DoThi::themCanh(int v, int w) {
    dsKe[v].push_back(w); // Them canh vao danh sach ke
}

void DoThi::duyetBFS(int s) {
    vector<bool> daTham(soDinh, false);
    queue<int> hangDoi;

    daTham[s] = true;
    hangDoi.push(s);

    while (!hangDoi.empty()) {
        int v = hangDoi.front();
        cout << v << " ";
        hangDoi.pop();

        for (int i : dsKe[v]) {
            if (!daTham[i]) {
                daTham[i] = true;
                hangDoi.push(i);
            }
        }
    }
    cout << endl;
}

void DoThi::DFSHoTro(int v, vector<bool>& daTham) {
    daTham[v] = true;
    cout << v << " ";

    for (int i : dsKe[v]) {
        if (!daTham[i])
            DFSHoTro(i, daTham);
    }
}

void DoThi::duyetDFS(int s) {
    vector<bool> daTham(soDinh, false);
    DFSHoTro(s, daTham);
    cout << endl;
}

int main() {
    DoThi g(7); // Ðo thi có 7 dinh (S, A, B, C, D, E, F, G)

    // Them cac canh theo Hinh 5
    g.themCanh(0, 1); // S -> A
    g.themCanh(0, 2); // S -> B
    g.themCanh(0, 3); // S -> C
    g.themCanh(1, 4); // A -> D
    g.themCanh(2, 5); // B -> E
    g.themCanh(3, 6); // C -> F
    g.themCanh(4, 6); // D -> G
    g.themCanh(5, 6); // E -> G

    cout << "Duyet BFS bat dau tu S (0): ";
    g.duyetBFS(0);

    cout << "Duyet DFS bat dau tu S (0): ";
    g.duyetDFS(0);

    return 0;
}

