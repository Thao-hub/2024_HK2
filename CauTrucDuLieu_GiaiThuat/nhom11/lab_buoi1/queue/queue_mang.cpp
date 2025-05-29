#include <iostream>
#define MAX 100//kich thuoc hang doi using namespace std; 
using namespace std;

struct Queue { 
    int data[MAX]; //mang luu phan tu hang doi
	int Front, Rear; //chi so dau va cuoi hang doi
};

//khoi tao hang doi void
void Init_queue(Queue &q){
	q.Front = q.Rear = -1;
}

//kiem tra hang doi co rong khong
bool isEmpty(Queue q){
	return q.Front == -1;
}

//kiem tra hang doi co day khong
bool isFull(Queue q){
	return q.Rear == MAX -1;
}

//them phan tu vao hang doi (enqueue) 
bool Enqueue(Queue &q, int x){
	if(isFull(q)){
		cout<<"Hang doi day, khong the them phan tu!\n";
		return false;
	}
	if(isEmpty(q)){
		q.Front = 0;
	}
	q.Rear ++;
	q.data[q.Rear] = x;
	return true;
}

// xoa phan tu khoi hang doi (dequeue) 
bool Dequeue(Queue &q, int &x) { 
    if (isEmpty(q)) { 
        cout << "Hang doi rong , khong the xoa phan tu\n";
		return false; 
    } 
    x = q.data[q.Front]; 
	q.Front++; 
    if (q.Front > q.Rear) {
	    //neu sau khi xoa hang doi rong   
		Init_queue(q); 
    } 
    return true; 
} 

// hien thi hang doi
void Display(Queue q) {     
	if (isEmpty(q)) { 
        cout << "Hang doi rong.\n";
		return; 
    } 
    cout << "Hang doi: "; 
    for (int i = q.Front; i <= q.Rear; i++) {         
		cout << q.data[i] << " "; 
    } 
    cout << endl; 
} 

// xuat va dem cac phan tu chan trong hang doi 
void DisplayEvenNumbers(Queue q) {   
	if (isEmpty(q)) { 
	        cout << "Hang doi rong, khong co so chan!\n";         
			return; 
	    } 
	    int evenCount = 0; 
	    cout << "Cac phan tu chan trong hang doi: ";     
		for (int i = q.Front; i <= q.Rear; i++) {         
			if (q.data[i] % 2 == 0) {             
				cout << q.data[i] << " ";             
				evenCount++; 
	        } 
		}
	cout << "\nTong so phan tu chan: " << evenCount << endl;     
	cout << "Tong so phan tu trong hang doi: " << (q.Rear - q.Front + 1) << endl; 
}

int main() { 
    Queue q;     
	Init_queue(q); 
    int choice, x; 
    do { 
        cout << "\n--- MENU ---\n";         
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
            if (Enqueue(q, x)) { 
               cout << "Da them " << x << " vao hang doi.\n"; 
            }                 
			break;             
		case 2:                 
			if (Dequeue(q, x)) { 
                cout << "Da xoa " << x << " khoi hang doi.\n"; 
            }                 
			break;             
		case 3: 
            Display(q);                 
			break;             
		case 0: 
            cout << "Thoa khoi chuong trinh.\n";                 
			break;             
			default: 
            cout << "Lua chon khong hop le vui long nhap lai.\n"; 
        } 
    } while (choice != 0); 
    return 0; 
} 


