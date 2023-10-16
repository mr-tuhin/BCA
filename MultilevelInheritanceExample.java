// Base class (Superclass)
class Animal {
    void eat() {
        System.out.println("The animal is eating.");
    }
}

// Intermediate class inheriting from Animal
class Dog extends Animal {
    void bark() {
        System.out.println("The dog is barking.");
    }
}

// Derived class inheriting from Dog
class GermanShepherd extends Dog {
    void guard() {
        System.out.println("The German Shepherd is guarding.");
    }
}

public class MultilevelInheritanceExample {
    public static void main(String[] args) {
        // Create an object of the GermanShepherd class
        GermanShepherd myDog = new GermanShepherd();

        // Access methods from all three classes
        myDog.eat();    // Inherited from Animal class
        myDog.bark();   // Inherited from Dog class
        myDog.guard();  // Defined in the GermanShepherd class
    }
}
