import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BufferedReaderInput {
    public static void main(String[] args) {
        // Create a BufferedReader object to read input
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        try {
            System.out.print("Enter something: ");
            String input = reader.readLine();

            System.out.println("You entered: " + input);
        } catch (IOException e) {
            System.err.println("An error occurred while reading input.");
        } finally {
            try {
                reader.close(); // Close the BufferedReader
            } catch (IOException e) {
                System.err.println("An error occurred while closing the BufferedReader.");
            }
        }
    }
}
