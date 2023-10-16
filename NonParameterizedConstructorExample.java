class Car {
    String make;
    String model;
    int year;

    // Non-parameterized constructor
    public Car() {
        make = "Unknown";
        model = "Unknown";
        year = 0;
    }

    public void displayDetails() {
        System.out.println("Make: " + make);
        System.out.println("Model: " + model);
        System.out.println("Year: " + year);
    }
}

public class NonParameterizedConstructorExample {
    public static void main(String[] args) {
        // Create an object of the Car class using the non-parameterized constructor
        Car myCar = new Car();

        // Display car details
        System.out.println("Car Details:");
        myCar.displayDetails();
    }
}
