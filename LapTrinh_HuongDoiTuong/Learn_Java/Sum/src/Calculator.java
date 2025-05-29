import java.util.Scanner;

public class Calculator {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
	
		//nhap a b , dau
		System.out.println("Enter first number: ");
		double FirstNumber = sc.nextDouble();
		
		System.out.println("Enter an operator: ");
		String MathSimple = sc.next();
		
		System.out.println("Enter first number: ");
		double SecondNumber = sc.nextDouble();
		
		//check the math
		switch (MathSimple) {
		
		case "+":
			double Addition = FirstNumber + SecondNumber;
			System.out.println("Addition: " + Addition);
			break;
			
		case "-":
			double Subtraction = FirstNumber - SecondNumber;
			System.out.println("Subtraction: " + Subtraction);
			break;
			
		case "*":
			double Multiplication = FirstNumber * SecondNumber;
			System.out.println("Multiplication: " + Multiplication);
			break;
			
		case "/":
			//kt khong chia cho 0
			if(SecondNumber == 0) {
				System.out.println("Error. Can not be divied by zero!");
			}
			else {
				double Division = FirstNumber / SecondNumber;
				System.out.println("Division: " + Division );
			}
			break;
			
		default:
			System.out.println("Please enter the math(+, -, *, /)");
		}
	}
}

