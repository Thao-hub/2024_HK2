#include <iostream>
using namespace std;

// 1. Tinh tong binh phuong cac so tu 1 den n (de quy)
// Ban chat cua de quy la viec 1 ham tu goi chinh no
long tongBinhPhuong(int n) {
    // diem dung 
    if (n == 0) {
        return 0;
    }
    // Buoc de quy: Tong binh phuong cac so tu 1 den n bang tong binh phuong cac so tu 1 den (n-1) cong voi n^2.
    return tongBinhPhuong(n - 1) + n * n;
}

// 2. Tinh so Fibonacci thu n (su dung de quy)
// Ham tinhFibonacci nhan vao mot so nguyen duong n va tra ve so Fibonacci thu n.
// Day Fibonacci bat dau bang 0 va 1, cac so tiep theo la tong cua hai so truoc do (0, 1, 1, 2, 3, 5, ...).
int tinhFibonacci(int n) {
    // Truong hop co so:
    // Neu n la 0, so Fibonacci thu 0 la 0.
    if (n == 0) {
        return 0;
    }
    // Neu n la 1, so Fibonacci thu 1 la 1.
    else if (n == 1) {
        return 1;
    } else {
        // Buoc de quy:
        // So Fibonacci thu n bang tong cua so Fibonacci thu (n-1) va so Fibonacci thu (n-2).
        return tinhFibonacci(n - 1) + tinhFibonacci(n - 2);
    }
}

// 3. Tinh giai thua cua mot so n (su dung de quy)
// Ham tinhGiaiThua nhan vao mot so nguyen duong n va tra ve giai thua cua n (n!).
// Giai thua cua n la tich cua tat ca cac so nguyen duong tu 1 den n (vi du: 5! = 5 * 4 * 3 * 2 * 1 = 120).
long long tinhGiaiThua(int n) {
    // Truong hop co so:
    // Giai thua cua 0 la 1.
    if (n == 0) {
        return 1;
    } else {
        // Buoc de quy:
        // Giai thua cua n bang n nhan voi giai thua cua (n-1).
        return n * tinhGiaiThua(n - 1);
    }
}

// Ham main() la diem khoi dau, moi chuong trinh C++ bat buoc phai co 1 ham main(), khi chuong trinh da bien dich he dieu hanh se bat dau thuc hien cac lenh trong ham main()
// int la kieu du lieu tra ve cua ham main(), ham main() se tra ve gia tri nguyen (integer)
int main() {
    int n;

    // Nhap n mot lan duy nhat
    cout << "Nhap n: ";
    cin >> n;

    // Cau 1: Tinh tong binh phuong
    cout << "Tong binh phuong cua " << n << " so dau tien la: " << tongBinhPhuong(n) << endl;

    cout << endl;

    // Cau 2: Tinh Fibonacci
    cout << "So Fibonacci thu " << n << " la: " << tinhFibonacci(n) << endl;

    cout << endl;

    // Cau 3: Tinh giai thua
    cout << "Giai thua cua " << n << " la: " << tinhGiaiThua(n) << endl;

    return 0;
}

