class Employee {
    String name;
    int age;
    int phone_number;
    String address;
    double salary;

    Employee(String name, int age, int phone_number, String address, double salary) {  
        this.name = name;
        this.age = age;
        this.phone_number = phone_number;
        this.address = address;
        this.salary = salary;
    }

    void PrintSalary() {
        System.out.println(name + "'s' Salary : " + salary);
    }
}

class Officer extends Employee {
    String specialization;
    String designation;

    Officer(String name, int age, int phone_number, String address, double salary, String specialization, String designation) {
        super(name, age, phone_number, address, salary);
        this.specialization = specialization;
        this.designation = designation;
    }
}

class Manager extends Employee {
    String specialization;
    String designation;

    Manager(String name, int age, int phone_number, String address, double salary, String specialization, String designation) {
        super(name, age, phone_number, address, salary);
        this.specialization = specialization;
        this.designation = designation;
    }
}

class Main {
    public static void main(String[] args) {
        Officer o = new Officer("Abhay", 21, 123456789, "Delhi", 50000, "CSE", "Manager");
        Manager m = new Manager("Ankit", 22, 987654321, "Mumbai", 60000, "CSE", "Manager");
        o.PrintSalary();
        m.PrintSalary();
    }
}
