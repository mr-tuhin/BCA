import java.util.InputMismatchException;
import java.util.Scanner;

public class ExceptionHandlingExample {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int result = 0;

        try {
            System.out.print("Enter an integer: ");
            int numerator = scanner.nextInt();

            System.out.print("Enter another integer (denominator): ");
            int denominator = scanner.nextInt();

            // Attempt to perform division
            result = numerator / denominator;

            System.out.println("Result of division: " + result);
        } catch (InputMismatchException e) {
            System.err.println("Input error: Please enter valid integers.");
        } catch (ArithmeticException e) {
            System.err.println("Division by zero is not allowed.");
        } finally {
            scanner.close();
        }
    }
}
