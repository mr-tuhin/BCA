class Student {
    String name;
    int age;

    // Parameterized constructor
    public Student(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void displayDetails() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
    }
}

public class ParameterizedConstructorExample {
    public static void main(String[] args) {
        // Create an object of the Student class using the parameterized constructor
        Student student1 = new Student("Alice", 20);
        Student student2 = new Student("Bob", 22);

        // Display student details
        System.out.println("Student 1 Details:");
        student1.displayDetails();

        System.out.println("\nStudent 2 Details:");
        student2.displayDetails();
    }
}
