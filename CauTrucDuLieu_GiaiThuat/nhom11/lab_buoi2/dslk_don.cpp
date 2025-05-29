#include <iostream>
#include <string>
using namespace std;

// Cau truc sinh vien
struct SinhVien {
    int maSo;       // Ma so sinh vien
    string ho;      // Ho sinh vien
    string ten;     // Ten sinh vien
};

// Cau truc node
struct Node {
    SinhVien data;   // Du lieu sinh vien
    Node* next;      // Con tro den node tiep theo
};

typedef Node* DanhSach;  // Doi ten con tro Node* thanh DanhSach cho ngan gon 
// Ham khoi tao danh sach rong
void init(DanhSach &head) {
    head = NULL;  // Khi khoi tao, danh sach rong (NULL)
}

// Ham tao node moi voi du lieu sinh vien
DanhSach taoNode(SinhVien sv) {
    DanhSach p = new Node;  // Cap phat bo nho cho node moi
    p->data = sv;           // Gan du lieu sinh vien cho node
    p->next = NULL;         // Node moi chua lien ket voi node nao
    return p;               // Tra ve node moi
}

// Ham them sinh vien vao dau danh sach
void themDau(DanhSach &head, SinhVien sv) {
    DanhSach p = taoNode(sv);  // Tao node moi tu sinh vien
    p->next = head;            // Node moi tro den head (dau danh sach cu)
    head = p;                  // Cap nhat head tro den node moi
}

// Ham them sinh vien vao vi tri bat ky trong danh sach
void themVaoViTri(DanhSach &head, SinhVien sv, int vt) {
    if (vt <= 0 || head == NULL) {  // Neu vi tri <= 0(sai logic may tu hieu la them dau ds) hoac danh sach rong  
        themDau(head, sv);          // Them vao dau danh sach
        return;
    }
    DanhSach p = head;              // Bat dau duyet danh sach tu head
    for (int i = 0; i < vt - 1 && p->next != NULL; i++) {
        p = p->next;                // Di chuyen den node truoc vi tri muon chen
    }
    DanhSach newNode = taoNode(sv);  // Tao node moi
    newNode->next = p->next;        // Node moi tro den node sau vi tri p
    p->next = newNode;               // P tro den node moi
}

// Ham nhap thong tin sinh vien
void nhapSV(SinhVien &sv) {
    cout << "Nhap ma so (0 de dung): ";
    cin >> sv.maSo;
    if (sv.maSo == 0) return;        // Neu ma so = 0 thi dung nhap
    cout << "Nhap ho: ";
    cin.ignore();                    // Loai bo ky tu '\n' trong bo dem
    getline(cin, sv.ho);            // Nhap ho
    cout << "Nhap ten: ";
    getline(cin, sv.ten);           // Nhap ten
}

// Ham tao danh sach sinh vien bang cach nhap nhieu lan
void taoDanhSach(DanhSach &head) {
    SinhVien sv;
    while (true) {
        nhapSV(sv);                 // Nhap thong tin sinh vien
        if (sv.maSo == 0) break;    // Neu ma so = 0 thi dung lai
        themDau(head, sv);          // Them sinh vien vao dau danh sach
    }
}

// Ham hien thi danh sach sinh vien
void hienThiDS(DanhSach head) {
    int i = 0;
    while (head != NULL) {          // Duyet danh sach den khi NULL
        cout << "Vi tri " << i++ << ": ";
        cout << head->data.maSo << " - " << head->data.ho << " " << head->data.ten << endl;
        head = head->next;          // Chuyen sang node ke tiep
    }
}

// Ham tinh do dai danh sach
int doDaiDS(DanhSach head) {
    int count = 0;
    while (head != NULL) {
        count++;                    // Dem so node trong danh sach
        head = head->next;
    }
    return count;
}

// Ham hieu chinh thong tin sinh vien tai vi tri vt
void hieuChinhSV(DanhSach head, int vt) {
    int i = 0;
    while (head != NULL && i < vt) {  // Duyet danh sach den vi tri can hieu chinh
        head = head->next;
        i++;
    }
    if (head == NULL) {
        cout << "Vi tri khong hop le.\n";  // Vi tri khong ton tai
        return;
    }
    cout << "Nhap thong tin moi cho sinh vien:\n";
    nhapSV(head->data);             // Cap nhat thong tin moi cho sinh vien
}

// Ham xoa sinh vien tai vi tri vt
void xoaSV(DanhSach &head, int vt) {
    if (head == NULL) return;     // Danh sach rong, khong lam gi
    if (vt == 0) {                // Xoa vi tri dau danh sach
        DanhSach temp = head;
        head = head->next;
        delete temp;              // Xoa node dau
        return;
    }
    DanhSach p = head;
    for (int i = 0; i < vt - 1 && p->next != NULL; i++) {
        p = p->next;               // Di chuyen den node truoc vi tri muon xoa
    }
    if (p->next == NULL) return;   // Vi tri khong ton tai
    DanhSach temp = p->next;
    p->next = temp->next;          // Xoa node tai vi tri vt
    delete temp;
}

// Ham tim vi tri sinh vien theo ma so
int timTheoMa(DanhSach head, int ma) {
    int vt = 0;
    while (head != NULL) {
        if (head->data.maSo == ma)
            return vt;            // Tra ve vi tri cua sinh vien
        head = head->next;
        vt++;
    }
    return -1;                    // Khong tim thay sinh vien
}

// Ham sap xep danh sach theo ma so tang dan
void sapXepTang(DanhSach &head) {
    for (DanhSach i = head; i != NULL; i = i->next) {
        DanhSach minNode = i;
        for (DanhSach j = i->next; j != NULL; j = j->next) {
            if (j->data.maSo < minNode->data.maSo)
                minNode = j;       // Tim node co ma so nho nhat
        }
        if (minNode != i) {
            swap(i->data, minNode->data);  // Doi cho du lieu giua i va minNode
        }
    }
}

// Ham chen sinh vien vao danh sach da sap xep tang dan
void chenTangDan(DanhSach &head, SinhVien sv) {
    DanhSach p = taoNode(sv);
    if (head == NULL || sv.maSo < head->data.maSo) {
        p->next = head;
        head = p;                 // Chen vao dau danh sach
        return;
    }
    DanhSach cur = head;
    while (cur->next != NULL && cur->next->data.maSo < sv.maSo) {
        cur = cur->next;          // Duyet danh sach de tim vi tri chen
    }
    p->next = cur->next;
    cur->next = p;               // Chen node vao vi tri thích h?p
}

// Ham xoa toan bo danh sach
void xoaToanBoDS(DanhSach &head) {
    while (head != NULL) {
        DanhSach temp = head;
        head = head->next;
        delete temp;              // Xoa tung node trong danh sach
    }
}

// Ham chinh
int main() {
    DanhSach ds;
    init(ds);  // Khoi tao danh sach rong

    int chon;

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Tao danh sach sinh vien\n";
        cout << "2. Them sinh vien vao danh sach\n";
        cout << "3. Xem danh sach sinh vien\n";
        cout << "4. Hieu chinh sinh vien\n";
        cout << "5. Xoa sinh vien theo vi tri\n";
        cout << "6. Tim sinh vien theo ma so\n";
        cout << "7. Sap xep danh sach theo ma so tang dan\n";
        cout << "8. Them sinh vien vao danh sach da sap xep\n";
        cout << "9. Xoa toan bo danh sach\n";
        cout << "0. Thoat\n";
        cout << "Chon chuc nang: ";
        cin >> chon;

        switch (chon) {
            case 1:
                taoDanhSach(ds);
                break;
            case 2: {
                SinhVien sv;
                nhapSV(sv);
                int vt;
                cout << "Nhap vi tri muon them: ";
                cin >> vt;
                themVaoViTri(ds, sv, vt);
                break;
            }
            case 3:
                hienThiDS(ds);
                break;
            case 4: {
                int vt;
                cout << "Nhap vi tri can hieu chinh: ";
                cin >> vt;
                hieuChinhSV(ds, vt);
                break;
            }
            case 5: {
                int vt;
                cout << "Nhap vi tri muon xoa: ";
                cin >> vt;
                xoaSV(ds, vt);
                break;
            }
            case 6: {
                int ma;
                cout << "Nhap ma so can tim: ";
                cin >> ma;
                int kq = timTheoMa(ds, ma);
                if (kq != -1)
                    cout << "Sinh vien o vi tri: " << kq << endl;
                else
                    cout << "Khong tim thay sinh vien.\n";
                break;
            }
            case 7:
                sapXepTang(ds);
                break;
            case 8: {
                SinhVien sv;
                nhapSV(sv);
                chenTangDan(ds, sv);
                break;
            }
            case 9:
                xoaToanBoDS(ds);
                cout << "Da xoa toan bo danh sach.\n";
                break;
            case 0:
                cout << "Tam biet!\n";
                break;
            default:
                cout << "Lua chon khong hop le.\n";
        }
    } while (chon != 0);

    xoaToanBoDS(ds); // Giai phong bo nho
    return 0;
}

