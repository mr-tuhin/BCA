// First interface
interface Flying {
    void fly();
}

// Second interface
interface Swimming {
    void swim();
}

// Concrete class implementing both Flying and Swimming interfaces
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

        // Access methods from both interfaces and the class
        bird.fly();
        bird.swim();
        bird.sing();
    }
}
