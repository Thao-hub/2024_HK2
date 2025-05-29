//nhap so nguyen n va xuat ra so fibonaci dau tien (khong de quy) 
#include <iostream>
using namespace std;

void Fibonacci(int n) {
    if (n <= 0) return;

    long long a = 0, b = 1; // Khoi tao hai so dau tien

    cout << "Day Fibonacci: ";
    for (int i = 0; i < n; i++) {
        cout << a << " "; // In so Fibonacci thu i
        long long temp = a + b;
        a = b;
        b = temp;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Nhap so nguyen n: ";
    cin >> n;

    Fibonacci(n); // Goi ham tinh day Fibonacci
    return 0;
}

