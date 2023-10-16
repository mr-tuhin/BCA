public class Employee {
    private String name;
    private int employeeId;

    // Parameterized constructor
    public Employee(String name, int employeeId) {
        this.name = name;
        this.employeeId = employeeId;
    }

    // Method to display employee details
    public void displayDetails() {
        System.out.println("Employee Name: " + name);
        System.out.println("Employee ID: " + employeeId);
    }

    public static void main(String[] args) {
        // Create an Employee object using the parameterized constructor
        Employee emp1 = new Employee("John Doe", 12345);

        // Call the displayDetails method to show the employee details
        emp1.displayDetails();
    }
}
