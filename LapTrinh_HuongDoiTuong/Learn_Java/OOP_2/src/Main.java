import java.util.ArrayList;
import java.util.Scanner;
public class Main {
	
	public static void main(String[] args) {
		
		Scanner scanner = new Scanner(System.in);
		System.out.print("Nhap so luong danh sach: ");
		int n = scanner.nextInt();

		Product[]dssp = new Product[n];
		
		for(int i = 0; i < n; i++) {
			System.out.println("Nhap thong tin san pham thu " +(i + 1)+": ");
			dssp[i] = new Product();
			dssp[i].InputProduct();
			System.out.println();
		}
		for(int i = 0; i < n; i++) {
			dssp[i].ShowProduct();
			System.out.println();
		}
		
		Supplier[]dsnsx = new Supplier[n];
		
		for(int i = 0; i < n; i++) {
			System.out.println("Nhap thong tin nha san xuat thu " +(i + 1)+": ");
			dsnsx[i] = new Supplier();
			dsnsx[i].InputSupplier();
			System.out.println();
		}
		
		for(int i = 0; i < n; i++) {
			dsnsx[i].ShowSupplier();
			System.out.println();
		}
		
		
//		
//		staff1.ShowProduct();
		
		
//		staff2.ShowSupplier();
		
	}

}



