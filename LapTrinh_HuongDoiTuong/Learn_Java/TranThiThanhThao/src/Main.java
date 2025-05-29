import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        DaySoNguyen ds = new DaySoNguyen();

        ds.Nhap();

        ds.SapTang();
        System.out.print("Dãy số sắp xếp tăng dần: ");
        ds.InDaySo();

        ds.SapGiam();
        System.out.print("Dãy số sắp xếp giảm dần: ");
        ds.InDaySo();

        System.out.print("Nhập giá trị x cần tìm: ");
        int x = sc.nextInt();
        if (ds.TimPhanTu(x) == 1) {
            System.out.println("Tìm thấy " + x);
        } else {
            System.out.println("Không tìm thấy " + x);
        }

        System.out.println("Tổng của dãy số: " + ds.TinhTong());
    }
}