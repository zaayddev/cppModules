#include "Array.hpp"
#include <iostream>

int main()
{
	{
		Array<int>	empty;

		std::cout << empty.size() << std::endl;
		try
		{
			std::cout << empty[2] << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
    std::cout << std::endl;
	{
		Array<int>	nul(5);

		std::cout << "nul size: " << nul.size() << std::endl;
		std::cout << "nul[0]: " << nul[0] << std::endl;
		std::cout << "nul[1]: " << nul[1] << std::endl;
		
		std::cout << "nul[0] = 3;" << std::endl;
		nul[0] = 3;
		std::cout << "nul[0]: " << nul[0] << std::endl;
	}
}
