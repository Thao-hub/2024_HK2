//Ten: Tran Thi Thanh Thao
//Mssv: 1250080179

import java.util.Arrays;
import java.util.Scanner;

class DaySoNguyen {
    private int n;
    private int[] arr;

    public void Nhap() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhập số phần tử n: ");
        n = sc.nextInt();
        arr = new int[n];

        System.out.println("Nhập các phần tử của dãy số:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
    }

    public void SapTang() {
        Arrays.sort(arr);
    }

    public void SapGiam() {
        Arrays.sort(arr);
        for (int i = 0; i < n / 2; i++) {
            int temp = arr[i];
            arr[i] = arr[n - 1 - i];
            arr[n - 1 - i] = temp;
        }
    }

    public int TimPhanTu(int x) {
        for (int value : arr) {
            if (value == x) {
                return 1; 
            }
        }
        return 0; 
    }

    public int TinhTong() {
        int sum = 0;
        for (int value : arr) {
            sum += value;
        }
        return sum;
    }

    public void InDaySo() {
        for (int value : arr) {
            System.out.print(value + " ");
        }
        System.out.println();
    }
}

