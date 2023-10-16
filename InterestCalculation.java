public class InterestCalculation {
    public static void main(String[] args) {
        // Define the variables
        double p = 1000.0; // Replace with your principal amount
        double t = 2.5;    // Replace with the time period in years
        double r = 5.0;    // Replace with the annual interest rate

        // Calculate the expression
        double i = (p * t * r) / 100;

        // Print the result
        System.out.println("The calculated interest (i) is: " + i);
    }
}
