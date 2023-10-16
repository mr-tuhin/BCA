public class CommandLineInput {
    public static void main(String[] args) {
        // Check if there are any command line arguments
        if (args.length > 0) {
            System.out.println("Command Line Arguments:");
            // Print each argument
            for (String arg : args) {
                System.out.println(arg);
            }
        } else {
            System.out.println("No command line arguments provided.");
        }
    }
}
