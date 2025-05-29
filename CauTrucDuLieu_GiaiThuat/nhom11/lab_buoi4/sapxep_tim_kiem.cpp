#include <iostream>
using namespace std;

#define MAX 100

void nhap(int a[], int &n) {
    cout << "Nhap so phan tu: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

void xuat(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void selection(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++){
        	if (a[j] < a[minIndex]){
        		minIndex = j;
			}
		}  
		if(minIndex !=i){
			swap(a[i], a[minIndex]);
		}
    }
}

void bubble(int a[], int n) {
    for (int i = 0; i < n - 1; i++){
    	for (int j = 0; j < n - 1 - i; j++){
    		if (a[j] > a[j + 1]){
    			swap(a[j], a[j + 1]);
			} 
		}
	} 
}

void insertion(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i]; 
		int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void quickSort(int a[], int left, int right) {
	int i, j, x;
    x = a[(left + right) / 2];
    i = left; j = right; 
    do{
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++; 
			j--;
        }
    }while (i<j);
    if (left < j) quickSort(a, left, j);
    if (right > i) quickSort(a, i, right);
}

// Các thu?t toán t?m ki?m
int linearSearch(int a[], int n, int x) {
    for (int i = 0; i < n; i++){
    	if (a[i] == x){
    		return i;
		} 
	}  
    return -1;
}

int binarySearch(int a[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x){
        	return mid;
		} 
        if (a[mid] < x){
        	left = mid + 1;
		} 
        else {
        	right = mid - 1;
		}
    }
    return -1;
}

int main() {
    int a[MAX], n = 0;
    int opt;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Nhap mang\n";
        cout << "2. Xuat mang\n";
        cout << "3. Selection Sort\n";
        cout << "4. Bubble Sort\n";
        cout << "5. Insertion Sort\n";
        cout << "6. Quick Sort\n";
        cout << "7. Linear Search\n";
        cout << "8. Binary Search (yeu cau sap xep truoc)\n";
        cout << "0. Thoat\n";
        cout << "Lua chon: ";
        cin >> opt;

        switch (opt) {
            case 1:
                nhap(a, n);
                break;
            case 2:
                cout << "Mang hien tai: ";
                xuat(a, n);
                break;
            case 3:
                selection(a, n);
                cout << "Mang sau Selection Sort: ";
                xuat(a, n);
                break;
            case 4:
                bubble(a, n);
                cout << "Mang sau Bubble Sort: ";
                xuat(a, n);
                break;
            case 5:
                insertion(a, n);
                cout << "Mang sau Insertion Sort: ";
                xuat(a, n);
                break;
            case 6:
                quickSort(a, 0, n - 1);
                cout << "Mang sau Quick Sort: ";
                xuat(a, n);
                break;
            case 7: {
                int x;
                cout << "Nhap gia tri can tim: ";
                cin >> x;
                int pos = linearSearch(a, n, x);
                if (pos != -1)
                    cout << "Tim thay tai vi tri a[" << pos << "]\n";
                else
                    cout << "Khong tim thay gia tri trong mang.\n";
                break;
            }
            case 8: {
                int x;
                cout << "Nhap gia tri can tim: ";
                cin >> x;
                quickSort(a, 0, n - 1); // ð?m b?o ð? s?p x?p
                int pos = binarySearch(a, n, x);
                if (pos != -1)
                    cout << "Tim thay tai vi tri a[" << pos << "]\n";
                else
                    cout << "Khong tim thay gia tri trong mang.\n";
                break;
            }
            case 0:
                cout << "Tam biet!\n";
                break;
            default:
                cout << "Lua chon khong hop le!\n";
        }

    } while (opt != 0);

    return 0;
}


