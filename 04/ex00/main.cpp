
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << std::endl;

	std::cout << "Dog getType = " << dog->getType() << std::endl;
	std::cout << "Cat getType = " << cat->getType() << std::endl;

	std::cout << "Cat sound: ";
	cat->makeSound();
	std::cout << "Dog sound: ";
	dog->makeSound();
	std::cout << "Animal sound: ";
	animal->makeSound();

	std::cout << std::endl << std::endl;

	delete animal;
	delete dog;
	delete cat;

	std::cout << std::endl;

	const WrongAnimal* crazy_animal = new WrongAnimal();
	const WrongAnimal* crazy_cat = new WrongCat();

	std::cout << std::endl;

	std::cout << "WrongCat sound: ";
	crazy_cat->makeSound();
	std::cout << "WrongAnimal sound: ";
	crazy_animal->makeSound();
	std::cout << std::endl;

	std::cout << std::endl;

	delete crazy_cat;
	delete crazy_animal;
}
