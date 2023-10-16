// First interface
interface Printable {
    void print();
}

// Second interface
interface Showable {
    void show();
}

// Concrete class implementing both Printable and Showable interfaces
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

        // Access methods from both interfaces
        obj.print();
        obj.show();
    }
}
