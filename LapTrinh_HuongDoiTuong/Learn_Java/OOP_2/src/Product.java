import java.util.Date;
import java.util.Scanner;
import java.text.SimpleDateFormat;


public class Product {
	private String ID;
	private String Name;
	private float Price;
	private Date MgfDate;
	private Date ExpiryDate ;
	
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
	
	public float getPrice() {
		return Price;
	}
	
	public void setPrice(float price) {
		this.Price = price;
	}
	
	public Date getMgfDate() {
		return MgfDate;
	}
	
	public void setMgfDate(Date mgfDate) {
		this.MgfDate = mgfDate;
	}
	
	public Date getExpiryDate() {
		return ExpiryDate;
	}
	
	public void setExpiryDate(Date expiryDate) {
		this.ExpiryDate = expiryDate;
	}
	
	
	public Product() {
		
	}
	public Product(String iD, String name) {
		this.ID = iD;
		this.Name = name;
	}
	
	public void InputProduct() {
	    Scanner scanner = new Scanner(System.in);
	    System.out.print("Nhap ID san pham: ");
	    this.ID = scanner.nextLine();

	    System.out.print("Nhap ten san pham: ");
	    this.Name = scanner.nextLine();

	    System.out.print("Nhap gia san pham: ");
	    this.Price = scanner.nextFloat();
	    scanner.nextLine(); 

	    SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");

	    try {
	        System.out.print("Nhap ngay san xuat (dd/MM/yyyy): ");
	        String mgfDateStr = scanner.nextLine();
	        this.MgfDate = formatter.parse(mgfDateStr);

	        System.out.print("Nhap han su dung (dd/MM/yyyy): ");
	        String expiryDateStr = scanner.nextLine();
	        this.ExpiryDate = formatter.parse(expiryDateStr);
	    } catch (Exception e) {
	        System.out.println("Loi: Dinh dang ngay khong hop le!");
	    }
	}

	
	public void ShowProduct() {
		System.out.println("Ma san pham: " +this.ID);
		System.out.println("Ten san pham: " +this.Name);
		System.out.println("Gia:" +this.Price);
		System.out.println("Ngay san xuat: " +this.MgfDate);
		System.out.println("Han su dung: " +this.ExpiryDate);
	}
	

}	
