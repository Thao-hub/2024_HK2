#include <iostream>
using namespace std;

struct Node{
	int info;
	Node*next;
};
typedef Node*Hangdoi;

struct Queue{
	Hangdoi Front, Rear;
};

void Init_queue(Queue & q){
	q.Front = q.Rear = nullptr;
}

bool Insert_queue(Queue &q, int x){
	Hangdoi p= new Node;
	if(!p){
		//p== nullptr
		cout<<"\nKhong du bo nho";
		return false;
	}
	p -> info = x;
	p -> next = nullptr;
	if(!q.Front){
		q.Front = p;
		//rong them 1 phan tu
	}
	else{
		q.Rear ->next = p;
		//gan q.Rear ->next len p
	}
	q.Rear = p;//cap nhat lai vi tri cuoi
	return true;
}

bool Delete_queue(Queue &q, int x){
	if(!q.Front){
		cout<<"\nHang doi rong.";
		return false;
	}
	Hangdoi p = q.Front;
	x = p->info;
	q.Front = p->next;//Front sang phan tu ke
	if(!q.Front){
		q.Rear = nullptr;
	}
	delete p;
	return true;
}

void Display_queue(const Queue &q){
	Hangdoi p= q.Front;
	if(!p){
		cout<<"\nHang doi rong.";
		return;
	}
	cout<<"\nHang doi: ";
	while(p){
		cout<< p->info<<" ";
		p = p -> next;
	}
	cout<<endl;
}

int main() {
    Queue q;
    Init_queue(q);
    int choice, x;

    do {
        cout << "\n--- MENU QUEUE DSLK ---\n";
        cout << "1. Them phan tu (Enqueue)\n";
        cout << "2. Xoa phan tu (Dequeue)\n";
        cout << "3. Hien thi hang doi\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Nhap gia tri can them: ";
            cin >> x;
            if (Insert_queue(q, x)) {
                cout << "Da them " << x << " vao hang doi.\n";
            }
            break;

        case 2:
            if (Delete_queue(q, x)) {
                cout << "Da xoa " << x << " khoi hang doi.\n";
            }
            break;

        case 3:
            Display_queue(q);
            break;

        case 0:
            cout << "Thoat chuong trinh.\n";
            break;

        default:
            cout << "Lua chon khong hop le. Vui long nhap lai.\n";
        }
    } while (choice != 0);
	
    return 0;
}

