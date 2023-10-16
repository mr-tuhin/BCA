class Person {
    String name;
    int age;

    // Parameterized constructor
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // Copy constructor
    public Person(Person other) {
        this.name = other.name;
        this.age = other.age;
    }

    public void displayDetails() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
    }
}

public class CopyConstructorExample {
    public static void main(String[] args) {
        // Create a Person object using the parameterized constructor
        Person person1 = new Person("Alice", 25);

        // Create another Person object using the copy constructor
        Person person2 = new Person(person1);

        // Display details of both persons
        System.out.println("Person 1 Details:");
        person1.displayDetails();

        System.out.println("\nPerson 2 Details (Copied from Person 1):");
        person2.displayDetails();
    }
}
