import java.util.Scanner;

public class SalaryCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input your Basic Salary
        System.out.print("Enter your Basic Salary: ");
        double basicSalary = scanner.nextDouble();

        // Input DA percentage
        System.out.print("Enter the DA percentage (e.g., 10 for 10%): ");
        double daPercentage = scanner.nextDouble();

        // Input HRA percentage
        System.out.print("Enter the HRA percentage (e.g., 20 for 20%): ");
        double hraPercentage = scanner.nextDouble();

        // Close the scanner
        scanner.close();

        // Calculate DA, HRA, and Gross Salary
        double da = (daPercentage / 100) * basicSalary;
        double hra = (hraPercentage / 100) * basicSalary;
        double grossSalary = basicSalary + da + hra;

        // Display the results
        System.out.println("Dearness Allowance (DA): " + da);
        System.out.println("House Rent Allowance (HRA): " + hra);
        System.out.println("Gross Salary: " + grossSalary);
    }
}
