#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
};
typedef struct node *Node;
 
void inite(Node &head) {
    head = NULL;
}

Node CreateNode(int x) {
    Node p = new node;
    p->data = x;
    p->next = NULL;
    return p;
}

void AddFirst(Node &head, int x) {
    Node p = CreateNode(x);
    if (head == NULL) {
        head = p;
        head->next = head;
    } else {
        Node q = head;
        while (q->next != head){
        	q = q->next;
		}
	    q->next = p;
	    p->next = head;
	    head = p;
    }
}

void AddLast(Node &head, int x) {
    Node p = CreateNode(x);
    if (head == NULL) {
        head = p;
        head->next = head;
    } else {
        Node q = head;
        while (q->next != head){
            q = q->next;
		}
        q->next = p;
        p->next = head;
    }
}

void AddAfter(Node &head, int x, int value) {
    if (head == NULL) return;
    Node q = head;
    do {
        if (q->data == x) {
            Node p = CreateNode(value);
            p->next = q->next;
            q->next = p;
            return;
        }
        q = q->next;
    } while (q != head);
}

void DeleteFirst(Node &head) {
    if (head == NULL) return;
    if (head->next == head) {
        delete head;
        head = NULL;
    } else {
        Node last = head;
        while (last->next != head){
            last = last->next;
		}
        Node temp = head;
        head = head->next;
        last->next = head;
        delete temp;
    }
}

void DeleteLast(Node &head) {
    if (head == NULL) return;
    if (head->next == head) {
        delete head;
        head = NULL;
    } else {
        Node prev = NULL, curr = head;
        while (curr->next != head) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = head;
        delete curr;
    }
}

void Output(Node head) {
    if (head == NULL) {
        cout << "Danh sach rong.\n";
        return;
    }
    Node p = head;
    do {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
    cout << endl;
}

void SortList(Node &head) {
    if (head == NULL || head->next == head) return;
    for (Node p = head; p->next != head; p = p->next) {
        for (Node q = p->next; q != head; q = q->next) {
            if (p->data > q->data)
                swap(p->data, q->data);
        }
    }
}

void DeleteAll(Node &head) {
    if (head == NULL) return;
    Node p = head->next;
    while (p != head) {
        Node temp = p;
        p = p->next;
        delete temp;
    }
    delete head;
    head = NULL;
}

// Giai bai toan Josephus
int Josephus(Node &head, int k) {
    if (head == NULL || head->next == head)
        return (head ? head->data : -1);

    Node p = head;
    Node prev = NULL;

    while (p->next != p) {
        // Di chuyen k-1 buoc
        for (int count = 1; count < k; count++) {
            prev = p;
            p = p->next;
        }

        // Loai nguoi tai p
        cout << "Loai nguoi: " << p->data << endl;
        prev->next = p->next;
        if (p == head) head = p->next;
        delete p;
        p = prev->next;
    }

    return p->data;
}

int main() {
    Node head;
    inite(head);  // Khoi tao danh sach rong

    int choice, x, val, k;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Them vao dau\n";
        cout << "2. Them vao cuoi\n";
        cout << "3. Them sau phan tu x\n";
        cout << "4. Xoa dau\n";
        cout << "5. Xoa cuoi\n";
        cout << "6. Liet ke\n";
        cout << "7. Sap xep tang\n";
        cout << "8. Xoa toan bo\n";
        cout << "9. Giai bai toan Josephus\n";  // ?? B? sung m?c m?i
        cout << "0. Thoat\n";
        cout << "Lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Nhap gia tri: ";
                cin >> x;
                AddFirst(head, x);
                break;
            case 2:
                cout << "Nhap gia tri: ";
                cin >> x;
                AddLast(head, x);
                break;
            case 3:
                cout << "Nhap gia tri x muon chen sau: ";
                cin >> x;
                cout << "Nhap gia tri moi: ";
                cin >> val;
                AddAfter(head, x, val);
                break;
            case 4:
                DeleteFirst(head);
                break;
            case 5:
                DeleteLast(head);
                break;
            case 6:
                Output(head);
                break;
            case 7:
                SortList(head);
                cout << "Danh sach da duoc sap xep.\n";
                Output(head);
                break;
            case 8:
                DeleteAll(head);
                cout << "Danh sach da bi xoa hoan toan.\n";
                break;
            case 9:
                if (head == NULL) {
                    cout << "Danh sach rong. Khong the giai bai toan Josephus.\n";
                } else {
                    cout << "Nhap buoc nhay k: ";
                    cin >> k;
                    int nguoiConLai = Josephus(head, k);
                    cout << "Nguoi song sot cuoi cung co gia tri: " << nguoiConLai << endl;
                }
                break;
            case 0:
                DeleteAll(head);  // Giai phong bo nho truoc khi thoat
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le.\n";
        }
    } while (choice != 0);

    return 0;
}


