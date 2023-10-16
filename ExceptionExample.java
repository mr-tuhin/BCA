class CustomException extends Exception {
    public CustomException(String message) {
        super(message);
    }
}

public class ExceptionExample {
    public static void main(String[] args) {
        try {
            // Simulate an error condition and throw a custom exception
            int age = -5;
            if (age < 0) {
                throw new CustomException("Age cannot be negative.");
            }

            // The code here will not be executed if the exception is thrown
            System.out.println("Age is: " + age);
        } catch (CustomException e) {
            // Catch and handle the custom exception
            System.err.println("Error: " + e.getMessage());
        }
    }
}
