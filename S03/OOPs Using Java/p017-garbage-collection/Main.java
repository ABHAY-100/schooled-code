public class Main {
    public static void main(String[] args) {
        Runtime runtime = Runtime.getRuntime();
        Integer someints[] = new Integer[1000];
        System.out.println("Total Memory       : " + runtime.totalMemory());
        System.out.println("Initial Free Memory: " + runtime.freeMemory());

        runtime.gc();
        System.out.println("Final Free Memory  : " + runtime.freeMemory());
    }
}
