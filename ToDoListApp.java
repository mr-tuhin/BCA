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
