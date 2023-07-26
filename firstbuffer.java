import java.io.*;
class firstbuffer 
 {
 public static void main(String args[])throws IOException
 {
 
    InputStreamReader read = new InputStreamReader(System.in);
    BufferedReader br = new BufferedReader(read);
    String name = br.readLine();
    int t=Integer.parseInt(br.readLine());
    double p= Double.parseDouble(br.readLine());
    char s=(char) br.read();
    System.out.println(name);
    System.out.println(p);
    System.out.println(t);
    System.out.println(s);
   }
 }

