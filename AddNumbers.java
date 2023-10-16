import java.util.Scanner;

public class AddNumbers {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Prompt the user to enter the value of 'a'
        System.out.print("Enter the value of 'a': ");
        int a = scanner.nextInt();

        // Prompt the user to enter the value of 'b'
        System.out.print("Enter the value of 'b': ");
        int b = scanner.nextInt();

        // Close the Scanner as we no longer need it
        scanner.close();

        // Calculate the sum of 'a' and 'b'
        int sum = a + b;

        // Print the result
        System.out.println("The sum of 'a' and 'b' is: " + sum);
    }
}
