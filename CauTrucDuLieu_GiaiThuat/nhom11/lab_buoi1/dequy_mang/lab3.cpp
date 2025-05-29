//xuat ra  so fibonaci o vi tri n(de quy)
#include <iostream>
using namespace std;

// Ham de quy tinh so Fibonacci o vi tri thu n
int fibonacci(int n) {
    // Dieu kien co ban: F(0) = 0, F(1) = 1
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    // Goi de quy de tinh F(n-1) + F(n-2)
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "Nhap mot so nguyen duong n: ";
    cin >> n;

    // In ra so Fibonacci o vi tri thu n
    cout << "So Fibonacci o vi tri thu " << n << " la: " << fibonacci(n) << endl;

    return 0;
}

