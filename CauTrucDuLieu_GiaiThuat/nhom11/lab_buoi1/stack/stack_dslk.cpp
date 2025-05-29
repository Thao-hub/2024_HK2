#include <iostream>
using namespace std;

struct Node{
	int info;
	Node* next;
};
typedef Node*Stack;

void Init_stack(Stack & sp){
	sp = nullptr;
}

void push(Stack & sp, int x){
	Stack p = new Node;
	if(!p){// p = nullptr
		cout<<"\nKhong du bo nho!";
		return;
	} 
	p -> info = x;
	p -> next = sp;//gan lien ket p va stack sp
	sp = p; //cap nhat lai phan tu dau
}

int pop(Stack & sp, int x){
	if(!sp){
		cout<<"\nStack rong.";
		return -1;
	}
	Stack p = sp;
	p-> info = x;//lay gia tri x tu stack
	p->next = sp;//chuyen sp sang vi tri ke de p roi
	delete p;
	return x;
}

void Display_stack(Stack sp){
	if(!sp){
		cout<<"\nStack rong.";
		return;	
	}
	cout<<"\nStack: ";
	while(sp){
		//sp != NULL
		cout<<sp -> info<<" ";
		sp = sp->next;//cho sp chay toi phan tu ke tiep 
	}
	cout<<endl;
}

int main() {
    Stack sp;
    Init_stack(sp);
    int choice, x;

    do {
        cout << "\n--- MENU STACK DSLK ---\n";
        cout << "1. Them phan tu (Push)\n";
        cout << "2. Xoa phan tu (Pop)\n";
        cout << "3. Hien thi Stack\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Nhap gia tri can them: ";
                cin >> x;
                push(sp, x);
                cout << "Da them " << x << " vao stack.\n";
                break;

            case 2:
                x = pop(sp);
                if (x != -1)
                    cout << "Da lay ra: " << x << " khoi stack.\n";
                break;

            case 3:
                Display_stack(sp);
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
