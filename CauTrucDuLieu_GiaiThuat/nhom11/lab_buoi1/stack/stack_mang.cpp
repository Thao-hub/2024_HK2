#include <iostream> 
#define STACKSIZE 100 
using namespace std; 
 
struct stack {
    int n;  
    int a[STACKSIZE];  
};

bool empty(stack &st){
	return st.n == -1;
}  

bool full(stack &st){
	return st.n == STACKSIZE - 1;
}
//them phan tu vao stack void 
void push(stack & st, int x){
	if (full(st)){
		cout<<"Stack bi day!" <<endl;
		return;
	}
	st.a[++(st.n)] = x;//tang n sau do gan x
	//tuong duong: st.n = st.n + 1;
}

//lay phan tu ra stack int
int pop(stack & st){
	if(empty(st)){
		cout<<"Stack bi rong!"<< endl;
		return -1;
	}
	return st.a[(st.n)--];
}

//in stack
void printStack(stack & st){
	if(empty(st)){
		cout<<"Stack rong!"<<endl;
		return;
	}
	cout<<"Stack: ";
	for(int i = 0; i <= st.n; i++){
		cout<<st.a[i]<<" ";
	}
	cout<<endl;
}

int main(){
	stack st;
	st.n = -1; // Kh?i t?o stack r?ng

	int choice, x;

	do {
		cout << "\n--- MENU STACK MANG ---\n";
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
				push(st, x);
				break;

			case 2:
				x = pop(st);
				if (x != -1)
					cout << "Da lay ra: " << x << " khoi stack.\n";
				break;

			case 3:
				printStack(st);
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
