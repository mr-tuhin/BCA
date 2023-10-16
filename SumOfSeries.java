import java.util.Scanner;

public class SumOfSeries {
    public static void main(String[] args) {
        // Create a Scanner object for user input
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter a positive integer N: ");
        int N = scanner.nextInt();

        if (N < 1) {
            System.out.println("Please enter a positive integer.");
        } else {
            int sum = 0;

            // Calculate the sum of the series
            for (int i = 1; i <= N; i++) {
                sum += i;
            }

            System.out.println("The sum of the first " + N + " natural numbers is: " + sum);
        }

        // Close the scanner
        scanner.close();
    }
}
