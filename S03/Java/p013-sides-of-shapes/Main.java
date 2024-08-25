abstract class Shape{
    abstract void numberOfSides();
}

class Triangle extends Shape{
    void numberOfSides(){
        System.out.println("Triangle has 3 sides");
    }
}

class Square extends Shape{
    void numberOfSides(){
        System.out.println("Square has 4 sides");
    }
}

class Circle extends Shape{
    void numberOfSides(){
        System.out.println("Circle has 0 sides");
    }
}

public class Main {
    public static void main(String[] args) {
        Triangle t = new Triangle();
        Square s = new Square();
        Circle c = new Circle();
        t.numberOfSides();
        s.numberOfSides();
        c.numberOfSides();
    }
}
