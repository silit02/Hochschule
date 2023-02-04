import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Geben Sie die erste Zahl ein: ");
        int z1 = scan.nextInt();
        System.out.println("Geben Sie die zweite Zahl ein: ");
        int z2 = scan.nextInt();
        try {
            System.out.println(z1 + " / " + z2 + " = " + divide(z1,z2));
        } catch (TestException e) {
            e.printStackTrace();
        } finally {
            System.out.println("Programmende");
        }
    }

    public static double divide(int z1, int z2) throws TestException {
        if(z2 == 0) {
            throw new TestException("Division durch 0");
        }
        return (double) z1 / (double) z2;
    }
}
