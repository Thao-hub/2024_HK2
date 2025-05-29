//tong binh phuong n so nguyen dau tien(de quy)
#include <iostream>
using namespace std;

int sum(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n * n + sum(n - 1);
    }
}

int main() {
    int n;
    cout << "Nhap mot so nguyen duong n: ";
    cin >> n;
    cout << "Tong cac binh phuong cua " << n << " so nguyen duong dau tien la: " << sum(n) << endl;
    return 0;
    
}

