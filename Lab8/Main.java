import java.util.Scanner;
import java.util.Random;

public class Main {
    static { System.loadLibrary("MyCPPLibrary"); }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of samples to generate: ");
        int numSamples = scanner.nextInt();

        int[] numbers = new int[numSamples];
        Random random = new Random();
        for (int i = 0; i < numSamples; i++) {
            numbers[i] = random.nextInt(101); // Generates numbers between 0 and 100
        }

        long timeBefore = System.currentTimeMillis();
        double mean = calculateMean(numbers);
        double stdDev = calculateSTDDev(numbers);
        long timeAfter = System.currentTimeMillis();

        System.out.println("Mean: " + mean);
        System.out.println("Standard Deviation: " + stdDev);
        System.out.println("Computation Time: " + (timeAfter - timeBefore) + " milliseconds");
    }

    // Native methods declarations
    public static native double calculateMean(int[] numbers);
    public static native double calculateSTDDev(int[] numbers);
}
