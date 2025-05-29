import java.util.Scanner;

public class NguyenDuong_do_while {
	public static void main(String[] args) {

	/* nhập số nguyên dương n (1 ≤n ≤ 100) từ bàn phím.

		Kiểm tra tính hợp lệ của n (“So vua nhap khong hop le”).
	*/
		Scanner sc = new Scanner(System.in);
		int n;
		
		do {
			System.out.print("Nhap so nguyen duong n(1 ≤ n ≤ 100): ");
			n = sc.nextInt();
			if(n < 1  || n > 100) {
				System.out.println("So vua nhap khong hop le! Vui long nhap lai.");
			}
		}while(n < 1  || n > 100 );

		System.out.println("So vua nhap la: " + n);
		sc.close();
	}
}
