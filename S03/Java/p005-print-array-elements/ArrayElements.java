// java program to print elements in an array
class ArrayElements {
    public static void main(String[] args) {
        int[] array = { 1, 2, 3, 4, 5 };

        System.out.print("Array elements: ");
        for(int ele : array) {
            System.out.print(" " + ele);
        }
        System.out.print("\n");
    }
}
