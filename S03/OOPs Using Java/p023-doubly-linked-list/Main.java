import java.util.Scanner;

class Node {
    int data;
    Node next;
    Node prev;

    Node(int data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

class DoublyLinkedList {

    Node head;

    public void insertAtBeginning(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            return;
        }
        newNode.next = head;
        head.prev = newNode;
        head = newNode;
    }

    public void insertAtEnd(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            return;
        }
        Node last = head;
        while (last.next != null) {
            last = last.next;
        }
        last.next = newNode;
        newNode.prev = last;
    }

    public void insertAtPosition(int data, int position) {
        if (position == 0) {
            insertAtBeginning(data);
            return;
        }

        Node newNode = new Node(data);
        Node current = head;

        for (int i = 0; i < position - 1 && current != null; i++) {
            current = current.next;
        }

        if (current == null) {
            System.out.println("Position out of bounds. Appending at the end.");
            insertAtEnd(data);
            return;
        }

        newNode.next = current.next;
        if (current.next != null) {
            current.next.prev = newNode;
        }

        current.next = newNode;
        newNode.prev = current;
    }

    public void deleteFromBeginning() {
        if (head == null) {
            System.out.println("List is empty.");
            return;
        }

        head = head.next;
        if (head != null) {
            head.prev = null;
        }
    }

    public void deleteFromEnd() {
        if (head == null) {
            System.out.println("List is empty.");
            return;
        }

        Node last = head;

        while (last.next != null) {
            last = last.next;
        }

        if (last.prev != null) {
            last.prev.next = null;
        } else {
            head = null;
        }
    }

    public void deleteAtPosition(int position) {
        if (head == null || position < 0) {
            System.out.println("List is empty or invalid position.");
            return;
        }

        Node current = head;

        if (position == 0) {
            deleteFromBeginning();
            return;
        }

        for (int i = 0; i < position && current != null; i++) {
            current = current.next;
        }

        if (current == null) {
            System.out.println("Position out of bounds.");
            return;
        }

        if (current.prev != null) {
            current.prev.next = current.next;
        }

        if (current.next != null) {
            current.next.prev = current.prev;
        }
    }

    public void displayForward() {
        Node current = head;

        if (current == null) {
            System.out.println("List is empty.");
            return;
        }

        while (current != null) {
            System.out.print(current.data + " <-> ");
            current = current.next;
        }

        System.out.println("null");
    }

    public void displayBackward() {
        Node current = head;

        while (current != null && current.next != null) {
            current = current.next;
        }

        if (current == null) {
            System.out.println("List is empty.");
            return;
        }

        while (current != null) {
            System.out.print(current.data + " <-> ");
            current = current.prev;
        }

        System.out.println("null");
    }
}

public class Main {

    public static void main(String[] args) {
        DoublyLinkedList dll = new DoublyLinkedList();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("\nMenu:");
            System.out.println("1. Insert at beginning");
            System.out.println("2. Insert at end");
            System.out.println("3. Insert at a specific position");
            System.out.println("4. Delete from beginning");
            System.out.println("5. Delete from end");
            System.out.println("6. Delete at a specific position");
            System.out.println("7. Print list forward");
            System.out.println("8. Print list reverse");
            System.out.println("9. Exit");
            System.out.print("Enter your choice: ");

            int choice = scanner.nextInt();

            switch (choice) {
                case 1 -> {
                    System.out.print("Enter value to insert at beginning: ");
                    int beginValue = scanner.nextInt();
                    dll.insertAtBeginning(beginValue);
                }

                case 2 -> {
                    System.out.print("Enter value to insert at end: ");
                    int endValue = scanner.nextInt();
                    dll.insertAtEnd(endValue);
                }

                case 3 -> {
                    System.out.print("Enter value to insert: ");
                    int posValue = scanner.nextInt();
                    System.out.print("Enter position: ");
                    int positionToInsert = scanner.nextInt();
                    dll.insertAtPosition(posValue, positionToInsert);
                }

                case 4 ->
                    dll.deleteFromBeginning();

                case 5 ->
                    dll.deleteFromEnd();

                case 6 -> {
                    System.out.print("Enter position to delete: ");
                    int positionToDelete = scanner.nextInt();
                    dll.deleteAtPosition(positionToDelete);
                }

                case 7 -> {
                    System.out.println("Doubly Linked List (Forward):");
                    dll.displayForward();
                }

                case 8 -> {
                    System.out.println("Doubly Linked List (Backward):");
                    dll.displayBackward();
                }

                case 9 -> {
                    System.out.println("Exiting...");
                    scanner.close();
                    return;
                }

                default ->
                    System.out.println("Invalid choice. Please try again.");
            }
        }
    }
}
