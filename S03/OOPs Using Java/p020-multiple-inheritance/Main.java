interface Animal {
	void eat();
}

interface Vehicle {
	void drive();
}

class Car implements Animal, Vehicle {
	public void eat() {
		System.out.println("Car doesn't eat");
	}
	public void drive() {
		System.out.println("Car is driven");
	}
	void honk() {
		System.out.println("Car is honking");
	}
}

class Main {
	public static void main(String args[]) {
		Car myCar = new Car();
		myCar.eat();
		myCar.drive();
		myCar.honk();
	}
}
