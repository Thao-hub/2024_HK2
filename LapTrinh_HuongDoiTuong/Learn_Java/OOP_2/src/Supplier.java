import java.util.Scanner;

public class Supplier {
	private String ID;
	private String Name;
	private String PhNo;
	private String Address;
	
	public String getID() {
		return ID;
	}
	
	public void setID(String iD) {
		ID = iD;
	}
	
	public String getName() {
		return Name;
	}
	
	public void setName(String name) {
		this.Name = name;
	}
	
	public String getPhNo() {
		return PhNo;
	}

	public void setPhNo(String phno) {
		this.PhNo = phno;
	}

	public String getAddress() {
		return Address;
	}

	public void setAddress(String address) {
		this.Address = address;
	}
	
	public Supplier() {
		
	}
	public Supplier(String iD, String name, String phno) {
		this.ID = iD;
		this.Name = name;
		this.PhNo = phno;
	}
	
	public void InputSupplier() {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Nhap ID nha cung cap: ");
		this.ID = scanner.nextLine();
		
		System.out.print("Nhap ten nha cung cap: ");
		this.Name = scanner.nextLine();
		
		System.out.print("Nhap so dien thoai nha cung cap: ");
		this.PhNo = scanner.nextLine();
		
		System.out.print("Nhap dia chi nha cung cap: ");
		this.Address = scanner.nextLine();
		
	}
	
	public void ShowSupplier() {
		System.out.println("Ma nha cung cap: " +this.ID);
		System.out.println("Ten nha cung cap: " +this.Name);
		System.out.println("So dien thoai" +this.PhNo);
		System.out.println("Đia chi: " +this.Address);
	}
}
	