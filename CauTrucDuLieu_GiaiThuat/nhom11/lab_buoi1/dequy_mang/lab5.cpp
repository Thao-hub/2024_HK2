//de quy tinh: S(n) =  1 +1/(1+2) + 1 +1/(1+2+3) + ...+ 1 +1/(1+2+3+...+n)
#include <iostream>
using namespace std;

// Ham de quy tinh S(n)
double S(int n) {
    if (n == 1) return 1.0; // Dieu kien dung
    return S(n - 1) + 1.0 / (n * (n + 1) / 2); // Goi de quy
}

int main() {
    int n;
    cout << "Nhap so nguyen n: ";
    cin >> n;

    cout << "S(" << n << ") = " << S(n) << endl;
    return 0;
}

