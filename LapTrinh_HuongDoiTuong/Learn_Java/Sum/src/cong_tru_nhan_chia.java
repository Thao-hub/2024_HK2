import java.util.Scanner;
public class cong_tru_nhan_chia {

	public static void main(String[] args) {
		
		//Scanner cho phep nhap du lieu tu ban phim va doc du lieu
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Nhap so thu nhat: ");
		double a = sc.nextDouble();
		
		System.out.print("Nhap so thu nhat: ");
		double b = sc.nextDouble();
		
		double tong = a + b;
		double hieu = a - b;
		double tich = a * b;
		
		System.out.println("Tong la: " + tong);
		System.out.println("Hieu la: " + hieu);
		System.out.println("Tich la: " + tich);
		
		if(b == 0) {
			System.out.println("Loi. Khong the chia cho 0!");
		}
		else {
			double thuong = a / b;
			System.out.println("Thuong la: " + thuong);
		}
		
		
		
		sc.close();//dong scanner de tranh lang phi tai nguyen
	}

}
