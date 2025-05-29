#include <iostream>
using namespace std;

// 1. Khai bao cau truc 1 node cua cay nhi phan
struct node {
    int data;
    node *left;
    node *right;
};
typedef struct node Node;
typedef Node* TREE;

// 2. Khoi tao cay rong
void Initetree(TREE &t) {
    t = NULL;
}

// 3. Tao 1 node moi
Node* Createnode(int value) {
    Node* p = new node();
    p->data = value;
    p->left = nullptr;
    p->right = nullptr;
    return p;
}

// cau 1 va 2. Them node vao cay
void Insertnode(TREE &t, int x) {
    if (t == NULL) {
        Node *p = Createnode(x);
        t = p;
    } else if (x < t->data) {
        Insertnode(t->left, x);
    } else if (x > t->data) {
        Insertnode(t->right, x);
    }
}
// cau 3 duyet LNR 
void DuyetLNR(TREE t) {
    if (t != NULL) {
        DuyetLNR(t->left);
        cout << t->data << " ";
        DuyetLNR(t->right);
    }
}
// cau 4 Duyet cay theo thu tu LNR (trai - goc - phai) va chi in so chan
void DuyetLNRchan(TREE t) {
    if (t != NULL) {
        DuyetLNRchan(t->left);
        if (t->data % 2 == 0) { // Kiem tra neu la so chan
            cout << t->data << " ";
        }
        DuyetLNRchan(t->right);
    }
}

// cau 5. Duyet cay theo thu tu NLR (goc - trai - phai)
void DuyetNLR(TREE t) {
    if (t != NULL) {
        cout << t->data << " ";
        DuyetNLR(t->left);
        DuyetNLR(t->right);
    }
}

//cau  6. Dem so node cua cay(so nut la)
int DemSoNode(TREE t) {
    if (t == NULL) return 0;
    return 1 + DemSoNode(t->left) + DemSoNode(t->right);
}

//cau  7. Dem so nut trung gian

int DemSoNodeTrungGian(TREE t, bool isRoot = true) {
    if (t == NULL || (t->left == NULL && t->right == NULL)) return 0;

    int count;
    if (isRoot) {
        count = 0; 
    } else {
        count = 1;
    }

    return count + DemSoNodeTrungGian(t->left, false) + DemSoNodeTrungGian(t->right, false);
}


// cau 8. Tim nut lon nhat
int TimLonNhat(TREE t) {
    if (t == NULL) return -1;
    while (t->right != NULL) {
        t = t->right;
    }
    return t->data;
}

// cau 9. Tim nut nho nhat
int TimNhoNhat(TREE t) {
    if (t == NULL) return -1;
    while (t->left != NULL) {
        t = t->left;
    }
    return t->data;
}
// cau 10 xoa node 

void XoaNode(TREE &t, int x) {
    if (t == NULL) return;  

    if (x < t->data) {
        XoaNode(t->left, x);  
    } else if (x > t->data) {
        XoaNode(t->right, x);  
    } else {
        if (t->left == NULL && t->right == NULL) {
            delete t;
            t = NULL;
        } else if (t->left == NULL) {
            Node* temp = t;
            t = t->right;
            delete temp;
        } else if (t->right == NULL) {
            Node* temp = t;
            t = t->left;
            delete temp;
        } else {
            Node* temp = t->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }
            t->data = temp->data;  
            XoaNode(t->right, temp->data);  
        }
    }
}

// 11. Tinh chieu cao cua cay
int Height(TREE t) {
    if (t == NULL) return 0;
    return 1 + max(Height(t->left), Height(t->right));
}

// Menu chuong trinh
int main() {
    TREE t;
    Initetree(t);

    while (true) {
        system("cls");
        cout << "\n\n\t====== MENU ========";
        cout << "\n1. Nhap du lieu";
        cout << "\n2. Duyet cay theo LNR";
        cout << "\n3. Duyet cay theo LNR (chi in so chan)";
        cout << "\n4. Duyet cay theo NLR (xuat cay)";
        cout << "\n5. Dem tong so node";
        cout << "\n6. Dem so nut trung gian";
        cout << "\n7. Tim nut nho nhat";
        cout << "\n8. Tim nut lon nhat";
        cout << "\n9. Tinh chieu cao cua cay";
        cout << "\n10.Xoa mot node trong cay";
        cout << "\n0. Thoat chuong trinh";
        cout << "\n\n\t====================";

        int luachon;
        cout << "\nNhap lua chon: ";
        cin >> luachon;

        switch (luachon) {
            case 1: {
                int x;
                cout << "Nhap so nguyen x: ";
                cin >> x;
                Insertnode(t, x);
                break;
            }
            case 2:
                cout << "Duyet LNR: ";
                DuyetLNR(t);  // Duyet cây theo LNR
                cout << endl;
                system("pause");
                break;
            case 3:
                cout << "Duyet LNR (chi in so chan): ";
                DuyetLNRchan(t);  // Duyet cây theo LNR và ch? in s? ch?n
                cout << endl;
                system("pause");
                break;
            case 4:
                cout << "Duyet NLR (xuat cay): ";
                DuyetNLR(t);
                cout << endl;
                system("pause");
                break;
            case 5:
                cout << "Tong so node trong cay: " << DemSoNode(t) << endl;
                system("pause");
                break;
            case 6:
                cout << "So nut trung gian: " << DemSoNodeTrungGian(t) << endl;
                system("pause");
                break;
            case 7:
                cout << "Nut nho nhat: " << TimNhoNhat(t) << endl;
                system("pause");
                break;
            case 8:
                cout << "Nut lon nhat: " << TimLonNhat(t) << endl;
                system("pause");
                break;
            case 9:
                cout << "Chieu cao cua cay: " << Height(t) << endl;
                system("pause");
                break;
            case 10: {
			    int x;
			    cout << "Nhap gia tri can xoa: ";
			    cin >> x;
			    XoaNode(t, x);
			    cout << "Da xoa " << x << " (neu co trong cay)." << endl;
			    system("pause");
			    break;
				}
            case 0:
                cout << "Thoat chuong trinh.\n";
                return 0;
            default:
                cout << "Lua chon khong hop le!" << endl;
                system("pause");
        }
    }

    return 0;
}
