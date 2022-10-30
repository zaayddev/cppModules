#include "Dog.hpp"
#include "Cat.hpp"

int	main()
{
	std::cout << std::endl;
	{
		AAnimal*	animal[6];

		for (int i = 0; i < 3; i++)
		{
			animal[i] = new Cat();
			std::cout << std::endl;
		}
		for (int i = 3; i < 6; i++)
		{
			animal[i] = new Dog();
			std::cout << std::endl;
		}
		for (int i = 0; i < 6; i++)
		{
			std::cout << "<< " << animal[i]->getType() << " >>" << std::endl;
			animal[i]->makeSound();
			animal[i]->thoughts();
			std::cout << std::endl;
		}
		for (int i = 0; i < 6; i++)
		{
			delete animal[i];
			std::cout << std::endl;
		}
	}
}