// Base class (Superclass)
class Animal {
    void eat() {
        System.out.println("The animal is eating.");
    }
}

// First subclass inheriting from Animal
class Dog extends Animal {
    void bark() {
        System.out.println("The dog is barking.");
    }
}

// Second subclass inheriting from Animal
class Cat extends Animal {
    void meow() {
        System.out.println("The cat is meowing.");
    }
}

public class HierarchicalInheritanceExample {
    public static void main(String[] args) {
        // Create objects of the Dog and Cat classes
        Dog myDog = new Dog();
        Cat myCat = new Cat();

        // Access methods from the Animal class and their respective subclasses
        myDog.eat();   // Inherited from Animal class
        myDog.bark();  // Defined in the Dog class
        myCat.eat();   // Inherited from Animal class
        myCat.meow();  // Defined in the Cat class
    }
}
