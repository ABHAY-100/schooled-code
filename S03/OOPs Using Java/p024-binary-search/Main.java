public class Main {
    public static void main(String[] args) {
        int[] array = { 1, 2, 3, 4, 5, 6, 7 };
        int key = 4;
        BinarySearch b = new BinarySearch();
        b.Search(array, key);
    }
}

class BinarySearch {
    void Search(int array[], int key) {
        int start = 0;
        int end = array.length - 1;
        int mid;
        while (start <= end) {
            mid = (start + end) / 2;
            if (array[mid] == key) {
                System.out.println("The element " + key + " found at index: " + mid);
                return;
            } else if (array[mid] > key) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        System.out.println("Element not found in the array!");
    }
}