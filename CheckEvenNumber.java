import java.util.Scanner;

public class CheckEvenNumber {
    public static void main(String[] args) {
        // Create a Scanner object for user input
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int number = scanner.nextInt();

        // Check if the number is even
        if (number % 2 == 0) {
            System.out.println(number + " is an even number.");
        } else {
            System.out.println(number + " is not an even number.");
        }

        // Close the scanner
        scanner.close();
    }
}
