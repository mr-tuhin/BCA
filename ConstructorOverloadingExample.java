class Student {
    String name;
    int age;
    double gpa;

    // Constructor with no parameters
    public Student() {
        name = "Unknown";
        age = 0;
        gpa = 0.0;
    }

    // Constructor with name and age parameters
    public Student(String name, int age) {
        this.name = name;
        this.age = age;
        gpa = 0.0;
    }

    // Constructor with all parameters
    public Student(String name, int age, double gpa) {
        this.name = name;
        this.age = age;
        this.gpa = gpa;
    }

    public void displayDetails() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("GPA: " + gpa);
    }
}

public class ConstructorOverloadingExample {
    public static void main(String[] args) {
        // Create Student objects using different constructors
        Student student1 = new Student();
        Student student2 = new Student("Alice", 20);
        Student student3 = new Student("Bob", 22, 3.5);

        // Display student details
        System.out.println("Student 1 Details:");
        student1.displayDetails();

        System.out.println("\nStudent 2 Details:");
        student2.displayDetails();

        System.out.println("\nStudent 3 Details:");
        student3.displayDetails();
    }
}
