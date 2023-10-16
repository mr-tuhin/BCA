# OOP
OOP stands for Object-Oriented Programming, a programming paradigm that organizes code around objects, which are instances of classes representing real-world entities.

## Write a java programme for basic concept in java.
```JAVA
public class BasicJavaConcepts {
    public static void main(String[] args) {
        class Person {
            String name;
            int age;

            void introduce() {
                System.out.println("Hello, my name is " + name + " and I am " + age + " years old.");
            }
        }
        Person person1 = new Person();
        person1.name = "Alice";
        person1.age = 25;
        Person person2 = new Person();
        person2.name = "Bob";
        person2.age = 30;
        person1.introduce();
        person2.introduce();
    }
}
```
### Output
```
Hello, my name is Alice and I am 25 years old.
Hello, my name is Bob and I am 30 years old.
```
This program defines a Person class with name and age attributes, and an introduce method to print information about the person. It then creates two Person objects, sets their attributes, and calls the introduce method to introduce them.

## Write a Java basic program in java.
```JAVA
public class HelloWorld {
    public static void main(String[] args) {
        System.out.println("Hello, World!");
    }
}
```
This program defines a class called HelloWorld with a main method. Inside the main method, it uses System.out.println to output "Hello, World!" to the console when you run the program.
### Output
```
Hello, World!
```
## Write an Expression that is s= a*a+ 2*a*b+ b*b in java programme.

```JAVA
public class ExpressionCalculation {
    public static void main(String[] args) {
        double a = 5.0;
        double b = 3.0;
        double s = a * a + 2 * a * b + b * b;
        System.out.println("The result of the expression s = a*a + 2*a*b + b*b is: " + s);
    }
}
```
a and b with the specific numbers to use in your expression, and it will calculate and print the result.

### Output
```
The result of the expression s = a*a + 2*a*b + b*b is: 64.0
```

## Write an Expression that is i = (p*t*r)/100 in java programme.
```JAVA
public class InterestCalculation {
    public static void main(String[] args) {
        double p = 1000.0;
        double t = 2.5;
        double r = 5.0;
        double i = (p * t * r) / 100;
        System.out.println("The calculated interest (i) is: " + i);
    }
}
```
In this program, you can replace the values of p, t, and r with the specific numbers you want to use in your expression, and it will calculate and print the result.
### Output
```
The calculated interest (i) is: 125.0
```
## Write a java programme that check number is odd.
```JAVA 
import java.util.Scanner;

public class CheckOddNumber {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int number = scanner.nextInt();
        if (number % 2 != 0) {
            System.out.println(number + " is an odd number.");
        } else {
            System.out.println(number + " is not an odd number.");
        }
        scanner.close();
    }
}
```
This program takes a number as input from the user, calculates the remainder when dividing it by 2, and checks if the remainder is not equal to 0. If the remainder is not 0, it means the number is odd, and it prints that the number is odd. Otherwise, it prints that the number is not odd.
### Output
```
Enter a number: 4
4 is not an odd number.
```
## Write a java programme that add number of series.

```JAVA
import java.util.Scanner;

public class SumOfSeries {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a positive integer N: ");
        int N = scanner.nextInt();
        if (N < 1) {
            System.out.println("Please enter a positive integer.");
        } else {
            int sum = 0;
            for (int i = 1; i <= N; i++) {
                sum += i;
            }

            System.out.println("The sum of the first " + N + " natural numbers is: " + sum);
        }
        scanner.close();
    }
}
```

This program takes a positive integer N as input, then calculates and prints the sum of the first N natural numbers. It uses a loop to add the numbers from 1 to N to compute the sum.
### Output
```
Enter a positive integer N: 5
The sum of the first 5 natural numbers is: 15
```
## Write a java programme that print
```
*
* *
* * *
* * * *
* * * * *
```
```JAVA
public class StarPattern {
    public static void main(String[] args) {
        int n = 5;  // Number of rows
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }
    }
}
```
This program will print the pattern you mentioned with 5 rows of increasing stars. You can change the value of n to adjust the number of rows in the pattern.
### Output
```
* 
* * 
* * * 
* * * * 
* * * * * 
```
## Write a java programme that can take a input from “command line arguments” and then print it.
```JAVA
public class CommandLineInput {
    public static void main(String[] args) {
        if (args.length > 0) {
            System.out.println("Command Line Arguments:");
            for (String arg : args) {
                System.out.println(arg);
            }
        } else {
            System.out.println("No command line arguments provided.");
        }
    }
}
```
To run this program, you can compile it and then execute it from the command line with arguments. For example, if you compile the program into a file called CommandLineInput.java
### Output
```
Command Line Arguments:
40
```
## Write a java programme that can take input by using “buffer reader” and then print it.
```JAVA
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BufferedReaderInput {
    public static void main(String[] args) {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        try {
            System.out.print("Enter something: ");
            String input = reader.readLine();

            System.out.println("You entered: " + input);
        } catch (IOException e) {
            System.err.println("An error occurred while reading input.");
        } finally {
            try {
                reader.close();
            } catch (IOException e) {
                System.err.println("An error occurred while closing the BufferedReader.");
            }
        }
    }
}
```
### Output
```
Enter something: 45
You entered: 45
```
## Write a java programme that can take value of a and b by using “Scanner class” and then add them and print it.

```JAVA
import java.util.Scanner;

public class AddNumbers {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the value of 'a': ");
        int a = scanner.nextInt();
        System.out.print("Enter the value of 'b': ");
        int b = scanner.nextInt();
        int sum = a + b;
        System.out.println("The sum of a and b is: " + sum);
        scanner.close();
    }
}
```
This program uses the Scanner class to read values for a and b from the user. It then calculates the sum of these values and prints the result. Make sure to close the Scanner` when you're done using it.
### Output
```
Enter the value of 'a': 59
Enter the value of 'b': 70
The sum of 'a' and 'b' is: 129
```
## Write a java programe to calcute your DA, HRA and Gross salary.
```JAVA
import java.util.Scanner;

public class SalaryCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter your basic salary: ");
        double basicSalary = scanner.nextDouble();
        double daPercentage = 0.15; 
        double hraPercentage = 0.10;
        double da = basicSalary * daPercentage;
        double hra = basicSalary * hraPercentage;
        double grossSalary = basicSalary + da + hra;
        System.out.println("Dearness Allowance (DA): " + da);
        System.out.println("House Rent Allowance (HRA): " + hra);
        System.out.println("Gross Salary: " + grossSalary);
        scanner.close();
    }
}
```
### Output
```
Enter your Basic Salary: 20000
Enter the DA percentage (e.g., 10 for 10%): 10
Enter the HRA percentage (e.g., 20 for 20%): 20
Dearness Allowance (DA): 2000.0
House Rent Allowance (HRA): 4000.0
Gross Salary: 26000.0
```
## Write a java programme using parameterized constructor.

```JAVA
class Student {
    String name;
    int age;
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
        Student student1 = new Student("Alice", 20);
        Student student2 = new Student("Bob", 22);
        System.out.println("Student 1 Details:");
        student1.displayDetails();
        System.out.println("\nStudent 2 Details:");
        student2.displayDetails();
    }
}
```
In this program, we have a Student class with a parameterized constructor that takes name and age as parameters. When we create student1 and student2 objects, we pass values to the constructor. The displayDetails method is used to display the student's details.

When you run the program, it will create two Student objects with different names and ages, and then it will display their details using the displayDetails method.
### Output
```
Student 1 Details:
Name: Alice
Age: 20

Student 2 Details:
Name: Bob
Age: 22
```
## Write a java programme using Non-parameterized constructor.
```JAVA
class Car {
    String make;
    String model;
    int year;
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
        Car myCar = new Car();
        System.out.println("Car Details:");
        myCar.displayDetails();
    }
}
```
In this program, we have a Car class with a non-parameterized constructor. When we create a myCar object, it uses the non-parameterized constructor to set default values for make, model, and year. The displayDetails method is used to display the car's details.

When you run the program, it will create a Car object with default values, and then it will display those values using the displayDetails method.
### Output
```
Car Details:
Make: Unknown
Model: Unknown
Year: 0
```
## Write a java programme using Copy-constructor.
```JAVA
class Person {
    String name;
    int age;
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }
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
        Person person1 = new Person("Alice", 25);
        Person person2 = new Person(person1);
        System.out.println("Person 1 Details:");
        person1.displayDetails();
        System.out.println("\nPerson 2 Details (Copied from Person 1):");
        person2.displayDetails();
    }
}
```
In this program, we have a Person class with a parameterized constructor and a copy constructor. The copy constructor takes an instance of the same class (Person in this case) as a parameter and copies the values from that instance to the new instance.

When you run the program, it will create two Person objects, one using the parameterized constructor and the other using the copy constructor to copy the values from the first object. It then displays the details of both persons.
### Output
```
Person 1 Details:
Name: Alice
Age: 25

Person 2 Details (Copied from Person 1):
Name: Alice
Age: 25
```
## Write a java programme of constructor overloading.
```JAVA
class Student {
    String name;
    int age;
    double gpa;
    public Student() {
        name = "Unknown";
        age = 0;
        gpa = 0.0;
    }
    public Student(String name, int age) {
        this.name = name;
        this.age = age;
        gpa = 0.0;
    }
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
        Student student1 = new Student();
        Student student2 = new Student("Alice", 20);
        Student student3 = new Student("Bob", 22, 3.5);
        System.out.println("Student 1 Details:");
        student1.displayDetails();
        System.out.println("\nStudent 2 Details:");
        student2.displayDetails();
        System.out.println("\nStudent 3 Details:");
        student3.displayDetails();
    }
}
```
In this program, we have a Student class with three constructors, each with a different parameter list. This demonstrates constructor overloading. When you create Student objects, you can use different constructors to initialize their values. The displayDetails method is used to display the student's details.
### Output
```
Student 1 Details:
Name: Unknown
Age: 0
GPA: 0.0

Student 2 Details:
Name: Alice
Age: 20
GPA: 0.0

Student 3 Details:
Name: Bob
Age: 22
GPA: 3.5
```
## Write a java programme of function or method overloading.

```JAVA
class Calculator {
    public int add(int a, int b) {
        return a + b;
    }
    public double add(double a, double b) {
        return a + b;
    }
    public String add(String a, String b) {
        return a + b;
    }
}

public class MethodOverloadingExample {
    public static void main(String[] args) {
        Calculator calculator = new Calculator();
        int sum1 = calculator.add(5, 10);
        double sum2 = calculator.add(3.5, 4.5);
        String combined = calculator.add("Hello, ", "World!");
        System.out.println("Sum of integers: " + sum1);
        System.out.println("Sum of doubles: " + sum2);
        System.out.println("Concatenated strings: " + combined);
    }
}
```
In this program, we have a Calculator class with three methods named add, each with a different parameter list. This demonstrates method overloading. When you call the add method, Java determines which version to execute based on the number and types of arguments provided.

This allows you to use the same method name for different operations depending on the parameter types, making the code more readable and flexible.
### Output
```
Sum of integers: 15
Sum of doubles: 8.0
Concatenated strings: Hello, World!
```
## Write a java programme using single-inheritance.
```JAVA
class Animal {
    void eat() {
        System.out.println("The animal is eating.");
    }
}
class Dog extends Animal {
    void bark() {
        System.out.println("The dog is barking.");
    }
}
public class SingleInheritanceExample {
    public static void main(String[] args) {
        Dog myDog = new Dog();
        myDog.eat();
        myDog.bark();
    }
}
```
In this program, we have an Animal class as the base or superclass and a Dog class as the derived or subclass. The Dog class inherits from the Animal class, demonstrating single inheritance. The Dog class can access the eat method from the Animal class, and it also has its own method, bark.

When you create an object of the Dog class, it can access methods from both the base and derived classes, as shown in the main method.
### Output
```
The animal is eating.
The dog is barking.
```
## Write a java programme using Multilevel-inheritance.
```JAVA
class Animal {
    void eat() {
        System.out.println("The animal is eating.");
    }
}
class Dog extends Animal {
    void bark() {
        System.out.println("The dog is barking.");
    }
}
class GermanShepherd extends Dog {
    void guard() {
        System.out.println("The German Shepherd is guarding.");
    }
}

public class MultilevelInheritanceExample {
    public static void main(String[] args) {
        GermanShepherd myDog = new GermanShepherd();
        myDog.eat();
        myDog.bark();
        myDog.guard();
    }
}
```
In this program, we have three classes: Animal, Dog, and GermanShepherd. The Dog class inherits from the Animal class, and the GermanShepherd class inherits from the Dog class, demonstrating multilevel inheritance. The GermanShepherd class can access methods from all three classes.

When you create an object of the GermanShepherd class, it can access methods from the Animal and Dog classes (which are inherited) as well as its own methods.
### Output
```
The animal is eating.
The dog is barking.
The German Shepherd is guarding.
```
## Write a java programme using Hierarchical-inheritance.
```JAVA
class Animal {
    void eat() {
        System.out.println("The animal is eating.");
    }
}
class Dog extends Animal {
    void bark() {
        System.out.println("The dog is barking.");
    }
}
class Cat extends Animal {
    void meow() {
        System.out.println("The cat is meowing.");
    }
}

public class HierarchicalInheritanceExample {
    public static void main(String[] args) {
        Dog myDog = new Dog();
        Cat myCat = new Cat();
        myDog.eat();   
        myDog.bark();
        myCat.eat();
        myCat.meow();
    }
}
```

In this program, we have a base class Animal, and two subclasses, Dog and Cat, both of which inherit from the Animal class. This demonstrates hierarchical inheritance. Each subclass can access methods from the Animal class and has its own unique methods.

When you create objects of the Dog and Cat classes, they can access methods from the Animal class (which is inherited) as well as their own class-specific methods.

### Output
```
The animal is eating.
The dog is barking.
The animal is eating.
The cat is meowing.
```
## Write a java programme of Multiple-inheritance by using interface.
```JAVA
interface Flying {
    void fly();
}
interface Swimming {
    void swim();
}
class Bird implements Flying, Swimming {
    @Override
    public void fly() {
        System.out.println("The bird is flying.");
    }

    @Override
    public void swim() {
        System.out.println("The bird is swimming.");
    }

    public void sing() {
        System.out.println("The bird is singing.");
    }
}

public class MultipleInheritanceExample {
    public static void main(String[] args) {
        Bird bird = new Bird();
        bird.fly();
        bird.swim();
        bird.sing();
    }
}
```
In this program, we have two interfaces, Flying and Swimming, and a concrete class Bird that implements both interfaces. This demonstrates multiple inheritance through interfaces. The Bird class can access methods from both interfaces and its own class-specific methods.

When you create an object of the Bird class, it can access methods from both interfaces and its own methods.
### Output
```
The bird is flying.
The bird is swimming.
The bird is singing.
```
## Write a java programme of interface-inheritance.
```JAVA 
interface Printable {
    void print();
}

interface Showable {
    void show();
}

class MyClass implements Printable, Showable {
    @Override
    public void print() {
        System.out.println("Printing...");
    }

    @Override
    public void show() {
        System.out.println("Showing...");
    }
}

public class InterfaceInheritanceExample {
    public static void main(String[] args) {
        MyClass obj = new MyClass();
        obj.print();
        obj.show();
    }
}
```
In this program, we have two interfaces, Printable and Showable, and a concrete class MyClass that implements both interfaces. This demonstrates interface inheritance. The MyClass class can access methods from both interfaces.

When you create an object of the MyClass class, it can access methods from both Printable and Showable interfaces. This allows the class to define specific behavior for each interface it implements.

### Output
```
Printing...
Showing...
```
## Write a java programme which create an exception.
```JAVA
class CustomException extends Exception {
    public CustomException(String message) {
        super(message);
    }
}

public class ExceptionExample {
    public static void main(String[] args) {
        try {
            int age = -5;
            if (age < 0) {
                throw new CustomException("Age cannot be negative.");
            }
            System.out.println("Age is: " + age);
        } catch (CustomException e) {
            System.err.println("Error: " + e.getMessage());
        }
    }
}
```
In this program, a custom exception CustomException is created by extending the built-in Exception class. Inside the try block, we check if the age is negative, and if so, we throw the custom exception. The catch block then catches the exception and prints an error message.

When you run this program, it will throw the CustomException due to the negative age value, and the corresponding error message will be displayed. You can create different types of exceptions or use standard exceptions like NullPointerException or ArrayIndexOutOfBoundsException by intentionally causing errors in your code and using the throw statement to raise the exceptions.

### Output
```
Error: Age cannot be negative.
```

## Write a java programme for exception handling using try, catch block.
```JAVA
import java.util.InputMismatchException;
import java.util.Scanner;

public class ExceptionHandlingExample {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int result = 0;

        try {
            System.out.print("Enter an integer: ");
            int numerator = scanner.nextInt();

            System.out.print("Enter another integer (denominator): ");
            int denominator = scanner.nextInt();

            result = numerator / denominator;

            System.out.println("Result of division: " + result);
        } catch (InputMismatchException e) {
            System.err.println("Input error: Please enter valid integers.");
        } catch (ArithmeticException e) {
            System.err.println("Division by zero is not allowed.");
        } finally {
            scanner.close();
        }
    }
}
```
In this program, we use the try block to wrap code that might throw exceptions. We attempt to perform division within the try block, and if any exceptions occur, we catch them using the catch blocks. In this example, we catch two types of exceptions:

1. InputMismatchException: This is thrown if the user enters non-integer input.
2. ArithmeticException: This is thrown when attempting to divide by zero.
The finally block ensures that the Scanner is closed, even if an exception is thrown.

When you run this program, it will prompt the user for input and handle exceptions by displaying appropriate error messages.

### Output
```
Enter an integer: 5
Enter another integer (denominator): 2
Result of division: 2
```
## Write a java programme for implementing finally block.
```JAVA
import java.util.Scanner;

public class FinallyBlockExample {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        try {
            System.out.print("Enter an integer: ");
            int numerator = scanner.nextInt();

            System.out.print("Enter another integer (denominator): ");
            int denominator = scanner.nextInt();

            int result = numerator / denominator;

            System.out.println("Result of division: " + result);
        } catch (ArithmeticException e) {
            System.err.println("ArithmeticException: Division by zero is not allowed.");
        } catch (java.util.InputMismatchException e) {
            System.err.println("InputMismatchException: Please enter valid integers.");
        } finally {
            System.out.println("The 'finally' block always executes.");
            scanner.close();
        }
    }
}
```
In this program, we use a try block to handle user input, division, and potential exceptions. There are catch blocks to handle ArithmeticException and InputMismatchException as before. Regardless of whether an exception is thrown or not, the code inside the finally block will always execute.

When you run this program, it will prompt the user for input, handle exceptions, and then execute the finally block to close the Scanner object and display the message that says, "The 'finally' block always executes."
### Output
```
Enter an integer: 5
Enter another integer (denominator): 3
Result of division: 1
The 'finally' block always executes.
```
## Write a java program using Thread.
```JAVA
class MyThread extends Thread {
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println("Thread: " + i);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                System.err.println(e);
            }
        }
    }
}

public class ThreadExample {
    public static void main(String[] args) {
        MyThread thread1 = new MyThread();
        MyThread thread2 = new MyThread();

        thread1.start();
        thread2.start();
        for (int i = 1; i <= 5; i++) {
            System.out.println("Main: " + i);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                System.err.println(e);
            }
        }
    }
}
```
In this program, we create a MyThread class that extends the Thread class and overrides the run method. Inside the run method, the thread counts from 1 to 5 with a sleep between each count to simulate a delay.

In the main method, we create two instances of the MyThread class (thread1 and thread2) and start them using the start method. These two threads run in parallel with the main thread, which continues to execute its own logic.

When you run this program, you'll see that the two threads and the main thread execute concurrently, demonstrating the use of threads in Java.
### Output
```
Main: 1
Thread: 1
Thread: 1
Main: 2
Thread: 2
Thread: 2
Main: 3
Thread: 3
Thread: 3
Main: 4
Thread: 4
Thread: 4
Main: 5
Thread: 5
Thread: 5
```
# PROJECT
Project Idea: To-Do List Application

Project Description:
Create a console-based to-do list application in Java. Users should be able to add, view, update, and remove tasks from their to-do list.

Key Features:

Task Management: Users should be able to add tasks, mark tasks as completed, edit task details, and delete tasks.

Task Categories: Allow users to categorize tasks (e.g., work, personal, shopping).

Task Priority: Implement task priorities (e.g., high, medium, low) to help users prioritize their tasks.

Task Due Dates: Users can set due dates for tasks and view tasks sorted by due date.

Data Persistence: Store task data in a file or a local database to save and load tasks between application sessions.

User-Friendly Console Interface: Create a simple and easy-to-use text-based interface for interacting with the to-do list.

Technical Details:

Use core Java for the application logic. You can create classes to represent tasks, task categories, and implement features like sorting and filtering.

Implement basic file I/O or use a local database like SQLite to store task data.

Use Java's built-in libraries for user input and output through the console.

Consider creating a menu system or using command-line arguments to navigate through different features of the application.

Implement error handling and validation to ensure that the user's input is accurate and the application doesn't crash due to unexpected input.

Optionally, you can explore third-party libraries for creating a more user-friendly console interface, such as JLine.

This project will help you become more familiar with handling data, user input, and managing tasks in a Java application. It's a great way to practice object-oriented programming and file/database operations in Java.


```JAVA
import java.util.ArrayList;
import java.util.Scanner;

class Task {
    String description;
    boolean isCompleted;

    public Task(String description) {
        this.description = description;
        this.isCompleted = false;
    }
}

public class ToDoListApp {
    private ArrayList<Task> tasks;

    public ToDoListApp() {
        tasks = new ArrayList<>();
    }

    public void addTask(String description) {
        Task task = new Task(description);
        tasks.add(task);
        System.out.println("Task added: " + description);
    }

    public void viewTasks() {
        System.out.println("Tasks in your to-do list:");
        for (int i = 0; i < tasks.size(); i++) {
            Task task = tasks.get(i);
            String status = task.isCompleted ? "[X]" : "[ ]";
            System.out.println(i + ". " + status + " " + task.description);
        }
    }

    public static void main(String[] args) {
        ToDoListApp toDoList = new ToDoListApp();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("\nMenu:");
            System.out.println("1. Add Task");
            System.out.println("2. View Tasks");
            System.out.println("3. Exit");
            System.out.print("Choose an option: ");

            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume the newline character

            switch (choice) {
                case 1:
                    System.out.print("Enter task description: ");
                    String description = scanner.nextLine();
                    toDoList.addTask(description);
                    break;
                case 2:
                    toDoList.viewTasks();
                    break;
                case 3:
                    System.out.println("Goodbye!");
                    scanner.close();
                    System.exit(0);
                default:
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }
}
```
### Output
```

Menu:
1. Add Task
2. View Tasks
3. Exit
Choose an option: 1
Enter task description: Drink Watter
Task added: Drink Watter

Menu:
1. Add Task
2. View Tasks
3. Exit
Choose an option: 1
Enter task description: Go to sleep
Task added: Go to sleep

Menu:
1. Add Task
2. View Tasks
3. Exit
Choose an option: 2
Tasks in your to-do list:
0. [ ] Drink Watter
1. [ ] Go to sleep

Menu:
1. Add Task
2. View Tasks
3. Exit
Choose an option: 
```