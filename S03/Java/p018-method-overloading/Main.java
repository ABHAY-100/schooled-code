public class Main {
    public static void main(String args[]) {
        Area area = new Area();
        area.areaOfShape(5);
        area.areaOfShape(5, 10);
        area.areaOfShape(0.5, 10, 15);
    }
}

class Area {
    void areaOfShape(double r) {
        System.out.println("Area of Circle: " + 3.14*r*r);
    }
    void areaOfShape(double l, double b) {
        System.out.println("Area of Rectangle: " + l*b);
    }
    void areaOfShape(double c, double b, double h) {
        System.out.println("Area of Triangle: " + c*b*h);
    }
}
