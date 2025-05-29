//xuat ra  so fibonaci o vi tri n(khong de quy)
#include <iostream>
using namespace std;

// Ham tinh so Fibonacci o vi tri thu n (khong su dung de quy)
int fibonacci(int n) {
    // Neu n la 0 hoac 1, tra ve n ngay lap tuc
    if (n == 0) return 0;
    if (n == 1) return 1;

    int a = 0;  // F(0)
    int b = 1;  // F(1)
    int fib;    // Bien de luu so Fibonacci hien tai

    // Lap tu 2 den n de tinh so Fibonacci
    for (int i = 2; i <= n; i++) {
        fib = a + b; // F(n) = F(n-1) + F(n-2)
        a = b;       // F(n-1) tro thanh F(n-2)
        b = fib;     // F(n) tro thanh F(n-1)
    }

    return fib;  // Tra ve so Fibonacci o vi tri thu n
}

int main() {
    int n;
    cout << "Nhap mot so nguyen duong n: ";
    cin >> n;

    // In ra so Fibonacci o vi tri thu n
    cout << "So Fibonacci o vi tri thu " << n << " la: " << fibonacci(n) << endl;

    return 0;
}

