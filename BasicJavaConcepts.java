public class BasicJavaConcepts {
    public static void main(String[] args) {
        // Define a class
        class Person {
            String name;
            int age;

            void introduce() {
                System.out.println("Hello, my name is " + name + " and I am " + age + " years old.");
            }
        }

        // Create objects
        Person person1 = new Person();
        person1.name = "Alice";
        person1.age = 25;

        Person person2 = new Person();
        person2.name = "Bob";
        person2.age = 30;

        // Call methods
        person1.introduce();
        person2.introduce();
    }
}
