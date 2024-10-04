class Animal {
	void MakeSound() {
		System.out.println("Some animal sound");
	}
}

class Mammel extends Animal {
	void GiveBirth() {
		System.out.println("Giving birth");
	}
}

class Dog extends Mammel {
	void Bark() {
		System.out.println("Bow! Bow!");
	}
}

class Main {
	public static void main(String args[]) {
		Animal a = new Animal();
		Mammel m = new Mammel();
		Dog d = new Dog();
		a.MakeSound();
		m.GiveBirth();
		d.Bark();
	}
}

