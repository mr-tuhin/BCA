// Base class (Superclass)
class Animal {
    void eat() {
        System.out.println("The animal is eating.");
    }
}

// Derived class (Subclass) inheriting from Animal
class Dog extends Animal {
    void bark() {
        System.out.println("The dog is barking.");
    }
}

public class SingleInheritanceExample {
    public static void main(String[] args) {
        // Create an object of the Dog class
        Dog myDog = new Dog();

        // Access methods from both the base and derived classes
        myDog.eat();  // Inherited from Animal class
        myDog.bark(); // Defined in the Dog class
    }
}
