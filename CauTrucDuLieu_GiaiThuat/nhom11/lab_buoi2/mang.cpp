#include <iostream>             
#include <string>               
using namespace std;            

const int MAX = 100;             

// Khai bao cau truc (struct) de luu thong tin hoc vien
struct HocVien {
    int maso;                   
    string ho;                  
    string ten;                  
};

// Ham nhap 1 hoc vien
void nhap1HocVien(HocVien &hv) {
    cout << "  Ma so: ";
    cin >> hv.maso;              
    cin.ignore();                

    cout << "  Ho: ";
    getline(cin, hv.ho);        

    cout << "  Ten: ";
    getline(cin, hv.ten);       
}

// Ham nhap danh sach hoc vien
void nhapDanhSach(HocVien ds[], int &n) {
    do {
        cout << "Nhap so luong hoc vien (1-" << MAX << "): ";
        cin >> n;                // Nhap so luong hoc vien
    } while (n < 1 || n > MAX);  // Kiem tra dieu kien hop le
    cin.ignore();               

    for (int i = 0; i < n; i++) {
        cout << "\nHoc vien " << i + 1 << ":\n";
        nhap1HocVien(ds[i]);     // Goi ham nhap cho tung hoc vien
    }
}

// Ham hien thi danh sach hoc vien
void hienThi(HocVien ds[], int n) {
    if (n == 0) {
        cout << "Danh sach rong.\n"; // Neu danh sach rong
        return;
    }
    cout << "\n--- Danh sach hoc vien ---\n";
    for (int i = 0; i < n; i++) {
        cout << ds[i].maso << " - " << ds[i].ho << " " << ds[i].ten << endl; // In thong tin tung hoc vien
    }
}

// Ham sap xep danh sach theo ten tang dan
void sapXepTheoTen(HocVien ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].ten > ds[j].ten) {
                swap(ds[i], ds[j]); // Doi cho neu ten dung truoc lon hon ten dung sau
            }
        }
    }
}

void themHocVien(HocVien ds[], int &n, HocVien hvMoi) {
    if (n >= MAX) {
        cout << "Danh sach day, khong the them.\n";
        return;
    }

    int i = n - 1;
    while (i >= 0 && ds[i].ten > hvMoi.ten) {
        ds[i + 1] = ds[i];
        i--;
    }
    ds[i + 1] = hvMoi;
    n++;
    cout << "Da them hoc vien vao danh sach.\n";
}



// Ham tim hoc vien theo ma so, tra ve vi tri trong mang
int timTheoMa(HocVien ds[], int n, int maso) {
    for (int i = 0; i < n; i++) {
        if (ds[i].maso == maso)             // Neu tim thay
            return i;
    }
    return -1;                              // Khong tim thay
}

// Ham xoa hoc vien theo ma so
void xoaHocVien(HocVien ds[], int &n, int maso) {
    int viTri = -1;
    for (int i = 0; i < n; ++i) {
        if (ds[i].maso == maso) {
            viTri = i;
            break;
        }
    }

    if (viTri != -1) {
        for (int i = viTri; i < n - 1; ++i) {
            ds[i] = ds[i + 1];
        }
        n--;
        cout << "Da xoa hoc vien co ma so " << maso << endl;
    } else {
        cout << "Khong tim thay hoc vien can xoa.\n";
    }
}

// Ham hien thi menu lua chon
void hienThiMenu() {
    cout << "\n====== MENU ======\n";
    cout << "1. Nhap danh sach hoc vien\n";
    cout << "2. Hien thi danh sach\n";
    cout << "3. Sap xep theo ten\n";
    cout << "4. Them hoc vien giu thu tu ten\n";
    cout << "5. Tim hoc vien theo ma so\n";
    cout << "6. Xoa hoc vien theo ma so\n";
    cout << "0. Thoat\n";
    cout << "==================\n";
}

// Ham chinh chay chuong trinh
int main() {
    HocVien ds[MAX];           // Mang luu danh sach hoc vien
    int n = 0;                  // So luong hoc vien hien co
    int choice;                 // Bien lua chon cua nguoi dung

    do {
        hienThiMenu();         // Goi ham hien thi menu
        cout << "Chon chuc nang: ";
        cin >> choice;         // Nhap lua chon

        switch (choice) {
            case 1:
                nhapDanhSach(ds, n); // Nhap danh sach
                break;
            case 2:
                hienThi(ds, n);      // Hien thi danh sach
                break;
            case 3:
                sapXepTheoTen(ds, n); // Sap xep theo ten
                cout << "Da sap xep danh sach theo ten.\n";
                break;
            case 4: {
                if (n >= MAX) {
                    cout << "Danh sach da day. Khong the them.\n";
                    break;
                }
                HocVien moi;
                cout << "\nNhap thong tin hoc vien moi:\n";
                nhap1HocVien(moi);         // Nhap thong tin hoc vien moi
                themHocVien(ds, n, moi);   // Them vao danh sach dung thu tu
                cout << "Da them hoc vien vao danh sach.\n";
                break;
            }
            case 5: {
                int maso;
                cout << "Nhap ma so can tim: ";
                cin >> maso;               // Nhap ma so can tim
                int pos = timTheoMa(ds, n, maso); // Tim trong danh sach
                if (pos == -1)
                    cout << "Khong tim thay.\n";
                else {
                    cout << "Tim thay: " << ds[pos].maso << " - "
                         << ds[pos].ho << " " << ds[pos].ten << endl;
                }
                break;
            }
            case 6: {
                int maso;
                cout << "Nhap ma so can xoa: ";
                cin >> maso;               // Nhap ma so can xoa
                xoaHocVien(ds, n, maso);   // Goi ham xoa
                break;
            }
            case 0:
                cout << "Dang thoat chuong trinh...\n"; // Thoat chuong trinh
                break;
            default:
                cout << "Lua chon khong hop le. Vui long thu lai.\n"; // Bao loi neu lua chon sai
        }

    } while (choice != 0); // Lap lai den khi nguoi dung chon 0

    return 0; // Ket thuc chuong trinh
}

