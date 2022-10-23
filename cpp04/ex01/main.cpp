#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	{
		const Animal*	animal = new Animal("Cow");
		const Animal*	dog    = new Dog();
		const Animal*	cat    = new Cat();

		std::cout << "animal Type : " << animal->getType() 	<< std::endl;
		std::cout << "animal Type : " << dog->getType() 	<< std::endl;
		std::cout << "animal Type : " << cat->getType()    	<< std::endl;

		animal->makeSound();
		dog->makeSound();
		cat->makeSound();

		delete animal;
		delete cat;
		delete dog;
	}
	std::cout << std::endl;
	{
		const WrongAnimal*	wrong_animal = new WrongAnimal("wrongCow");
		const WrongAnimal*	wrong_cat = new WrongCat();

		std::cout << "wrong_animal getType : " << wrong_animal->getType() << std::endl;
		std::cout << "wrong_cat getType : " << wrong_cat->getType() << std::endl;

		wrong_animal->makeSound();
		wrong_cat->makeSound();

		delete wrong_animal;
		delete wrong_cat;
	}
}