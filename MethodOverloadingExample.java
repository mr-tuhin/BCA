class Calculator {
    // Method to add two integers
    public int add(int a, int b) {
        return a + b;
    }

    // Method to add two doubles
    public double add(double a, double b) {
        return a + b;
    }

    // Method to concatenate two strings
    public String add(String a, String b) {
        return a + b;
    }
}

public class MethodOverloadingExample {
    public static void main(String[] args) {
        Calculator calculator = new Calculator();

        // Method overloading allows us to use the same method name with different parameter types
        int sum1 = calculator.add(5, 10);
        double sum2 = calculator.add(3.5, 4.5);
        String combined = calculator.add("Hello, ", "World!");

        System.out.println("Sum of integers: " + sum1);
        System.out.println("Sum of doubles: " + sum2);
        System.out.println("Concatenated strings: " + combined);
    }
}
