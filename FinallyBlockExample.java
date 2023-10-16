import java.util.Scanner;

public class FinallyBlockExample {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try {
            System.out.print("Enter an integer: ");
            int numerator = scanner.nextInt();

            System.out.print("Enter another integer (denominator): ");
            int denominator = scanner.nextInt();

            int result = numerator / denominator;

            System.out.println("Result of division: " + result);
        } catch (ArithmeticException e) {
            System.err.println("ArithmeticException: Division by zero is not allowed.");
        } catch (java.util.InputMismatchException e) {
            System.err.println("InputMismatchException: Please enter valid integers.");
        } finally {
            System.out.println("The 'finally' block always executes.");
            scanner.close();
        }
    }
}
