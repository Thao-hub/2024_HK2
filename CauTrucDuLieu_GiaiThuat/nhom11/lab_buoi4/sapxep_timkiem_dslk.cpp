#include <iostream>
using namespace std;

// Cau truc node
struct Node {
    int data;   // Du lieu cua node
    Node* next; // Con tro den node tiep theo
};

// Ham tao node moi
Node* taoNode(int x) {
    Node* p = new Node;  // Tao node moi
    p->data = x;         // Gan gia tri cho data
    p->next = NULL;      // Node moi khong co next, tra ve NULL
    return p;            // Tra ve node moi
}

// Ham them node vao cuoi danh sach
void themCuoi(Node*& head, int x) {
    Node* moi = taoNode(x); // Tao node moi
    if (!head) {            // Neu danh sach rong
        head = moi;         // Gan head bang node moi
        return;
    }
    Node* temp = head;      // Khoi tao con tro temp chay qua danh sach
    while (temp->next)      // Duyet den node cuoi
        temp = temp->next;
    temp->next = moi;       // Gan next cua node cuoi toi node moi
}

// Ham nhap danh sach lien ket
void nhap(Node*& head, int& n) {
    cout << "Nhap so phan tu n: ";
    cin >> n; // Nhap so phan tu
    for (int i = 0; i < n; i++) {
        int x;
        cout << "a[" << i << "] = ";
        cin >> x;           // Nhap gia tri moi
        themCuoi(head, x);  // Them gia tri vao cuoi danh sach
    }
}

// Ham xuat danh sach
void xuat(Node* head) {
    cout << "Danh sach sau khi sap xep: ";
    Node* temp = head;      // Khoi tao con tro temp duyet danh sach
    while (temp) {          // Duyet het danh sach
        cout << temp->data << " "; // In du lieu cua node
        temp = temp->next;   // Di chuyen den node tiep theo
    }
    cout << endl;
}

// Ham hoan vi du lieu hai node
void hoanVi(Node* a, Node* b) {
    int tam = a->data;  // Luu tru du lieu cua node a
    a->data = b->data;  // Gan du lieu cua node b cho node a
    b->data = tam;      // Gan du lieu cua node a cho node b
}

// Selection sort
void selection(Node* head) {
    for (Node* i = head; i && i->next; i = i->next) {  // Duyet qua danh sach
        Node* minNode = i;                               // Khoi tao node minNode la node i
        for (Node* j = i->next; j; j = j->next) {        // Duyet tu node i den cuoi danh sach
            if (j->data < minNode->data) {                // Neu data cua node j < minNode
                minNode = j;                              // Cap nhat minNode
            }
        }
        if (minNode != i) 
		swap (i->data, minNode->data);              // Hoan vi node i va minNode
    }
}

// Bubble sort
void bubble(Node* head) {
    if (head == nullptr) return;  // Neu danh sach rong, thoat
    for (Node* i = head; i->next; i = i->next) {  // Duyet qua danh sach
        for (Node* j = head; j->next; j = j->next) { // Duyet danh sach va so sanh cac node lien ke
            if (j->data > j->next->data) {  // Neu data cua j > data cua j->next
                hoanVi(j, j->next);        // Hoan vi du lieu cua j va j->next
            }
        }
    }
}

// Insertion sort
void insertion(Node*& head) {
    Node* daSap = NULL;    // Danh sach da sap xep
    Node* hienTai = head;  // Khoi tao con tro hienTai cho danh sach
    while (hienTai) {      // Duyet qua danh sach
        Node* keTiep = hienTai->next;  // Luu tru node tiep theo
        if (!daSap || daSap->data >= hienTai->data) {  // Neu danh sach da sap xep rong hoac data cua daSap >= hienTai
            hienTai->next = daSap;    // Gan next cua hienTai ve daSap
            daSap = hienTai;          // Cap nhat daSap
        } else {
            Node* temp = daSap;
            while (temp->next && temp->next->data < hienTai->data) {  // Tim vi tri cua hienTai
                temp = temp->next;
            }
            hienTai->next = temp->next;  // Gan next cua hienTai
            temp->next = hienTai;        // Gan hienTai vao vi tri thich hop
        }
        hienTai = keTiep;  // Di chuyen toi node tiep theo
    }
    head = daSap;  // Cap nhat head cua danh sach
}

// quick sort 
Node* getTail(Node* cur) {
    while (cur && cur->next) cur = cur->next;
    return cur;
}

Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node *prev = NULL, *cur = head, *tail = pivot;

    while (cur != pivot) {
        if (cur->data < pivot->data) {
            if (!*newHead) *newHead = cur;
            prev = cur;
            cur = cur->next;
        } else {
            if (prev) prev->next = cur->next;
            Node* tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if (!*newHead) *newHead = pivot;
    *newEnd = tail;
    return pivot;
}

Node* quickSortRecur(Node* head, Node* end) {
    if (!head || head == end) return head;

    Node *newHead = NULL, *newEnd = NULL;
    Node* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        Node* temp = newHead;
        while (temp->next != pivot) temp = temp->next;
        temp->next = NULL;
        newHead = quickSortRecur(newHead, temp);
        getTail(newHead)->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, newEnd);
    return newHead;
}

void quickSort(Node*& head) {
    head = quickSortRecur(head, getTail(head));
}

// Tim kiem tuan tu
int timTuanTu(Node* head, int x) {
    int viTri = 0;  // Khoi tao vi tri tim thay
    while (head) {  // Duyet qua danh sach
        if (head->data == x) return viTri;  // Neu tim thay gia tri x, tra ve vi tri
        head = head->next;   // Di chuyen den node tiep theo
        viTri++;             // Tang vi tri
    }
    return -1;  // Khong tim thay gia tri
}

// Tim kiem nhi phan
int timNhiPhan(Node* head, int n, int x) {
    int* arr = new int[n];  // Tao mang chua du lieu
    Node* temp = head;
    for (int i = 0; i < n; i++) {
        arr[i] = temp->data;  // Sao chep du lieu vao mang
        temp = temp->next;     // Di chuyen den node tiep theo
    }

    int trai = 0, phai = n - 1;  // Khoi tao vi tri ban dau cho tim kiem nhi phan
    while (trai <= phai) {  // Duyet mang
        int giua = (trai + phai) / 2;
        if (arr[giua] == x) {  // Neu tim thay
            delete[] arr;  // Xoa mang
            return giua;   // Tra ve vi tri
        } else if (arr[giua] < x)
            trai = giua + 1;  // Dieu chinh vi tri trai
        else
            phai = giua - 1;  // Dieu chinh vi tri phai
    }
    delete[] arr;  // Xoa mang
    return -1;  // Khong tim thay
}

// Ham chinh
int main() {
    Node* head = NULL;  // Khoi tao danh sach rong
    int n, x, kq;
    int luaChon;

    nhap(head, n);  // Nhap danh sach

    cout << "\n=== CHON PHUONG PHAP SAP XEP ===\n";
    cout << "1. Selection Sort\n";
    cout << "2. Bubble Sort\n";
    cout << "3. Insertion Sort\n";
    cout << "4. Quick Sort\n";  // B? sung l?a ch?n Quick Sort
    cout << "Nhap lua chon cua ban: ";
    cin >> luaChon;

    switch (luaChon) {  // Chon phuong phap sap xep
        case 1: selection(head); break;
        case 2: bubble(head); break;
        case 3: insertion(head); break;
        case 4: quickSort(head); break;  // G?i hàm Quick Sort
        default: cout << "Lua chon khong hop le!\n"; return 0;
    }

    xuat(head);  // Xuat danh sach sau khi sap xep

    cout << "\nNhap gia tri can tim: ";
    cin >> x;  // Nhap gia tri can tim

    cout << "Chon kieu tim kiem:\n";
    cout << "1. Tim kiem tuan tu\n";
    cout << "2. Tim kiem nhi phan\n";
    cout << "Nhap lua chon: ";
    cin >> luaChon;

    if (luaChon == 1)
        kq = timTuanTu(head, x);  // Tim kiem tuan tu
    else if (luaChon == 2)
        kq = timNhiPhan(head, n, x);  // Tim kiem nhi phan
    else {
        cout << "Lua chon khong hop le!\n";
        return 0;
    }

    if (kq != -1)
        cout << "Tim thay " << x << " tai vi tri: " << kq << endl;  // In vi tri tim thay
    else
        cout << "Khong tim thay " << x << endl;  // Khong tim thay gia tri

    return 0;
}


