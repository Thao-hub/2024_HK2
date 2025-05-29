
public class in_SoChan {

	public static void main(String[] args) {
		// In ra các số chẵn từ 1-20 nhưng bỏ qua các số chia hết cho 4
		System.out.println("Cac so chan tu 1 den 20 (bo qua so chia het cho 4):");
		//println: in ra du lieu nhung tu dong xuong dong
		for(int i = 1; i <=20; i++) {
			
			if((i % 2 == 0) && (i % 4 != 0)) {
				
				System.out.print(i + " ");
				//print: in ra du lieu khong xuong dong
			}
		}
	}

}
