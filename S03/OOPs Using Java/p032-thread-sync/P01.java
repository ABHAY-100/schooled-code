class Printer {
    synchronized public void print(String data) {
        for (int i=0; i<10; i++) {
            for (int j=0; j<i; j++) {
                System.out.print(data);
            }
            System.out.println();
        }
    }
}

class Star extends Thread {
    Printer printer;

    Star(Printer printer) {
        this.printer = printer;
    }
    public void run() {
        printer.print("*");
    }
}

class Hash extends Thread {
    Printer printer;

    Hash(Printer printer) {
        this.printer = printer;
    }
    public void run() {
        printer.print("#");
    }
}

public class P01 {
    public static void main(String args[]) {
        Printer printer = new Printer();
        Hash hash = new Hash(printer);
        Star star = new Star(printer);
        hash.start();
        star.start();

        try {
            hash.join();
            star.join();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}