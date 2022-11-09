#include "iter.hpp"
#include <iostream>

template<typename T>
void	square(T &x)
{
	x = x * x;
}

template<typename T>
void	cube(T &x)
{
	x = x * x * x;
}

template<typename T>
void	show(T &x)
{
	std::cout << x << " | ";
}

int main()
{
	{
		int	array[5] = {0, 1, 2, 3, 4};

		iter(array, 5, square);
		iter(array, 5, show);
		std::cout << std::endl;
	}
	{
		int	array[5] = {0, 1, 2, 3, 4};
		
		iter(array, 5, cube);
		iter(array, 5, show);
		std::cout << std::endl;
	}
	return (0);
}
