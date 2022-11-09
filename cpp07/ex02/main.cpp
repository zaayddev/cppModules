#include "Array.hpp"
#include <iostream>

// int main()
// {
// 	{
// 		Array<int>	empty;

// 		std::cout << empty.size() << std::endl;
// 		try
// 		{
// 			std::cout << empty[2] << std::endl;
// 		}
// 		catch (std::exception& e)
// 		{
// 			std::cout << e.what() << std::endl;
// 		}
// 	}
//     std::cout << std::endl;
// 	{
// 		Array<int>	nul(5);

// 		std::cout << "nul size: " << nul.size() << std::endl;
// 		std::cout << "nul[0]: " << nul[0] << std::endl;
// 		std::cout << "nul[1]: " << nul[1] << std::endl;
		
// 		std::cout << "nul[0] = 3;" << std::endl;
// 		nul[0] = 3;
// 		std::cout << "nul[0]: " << nul[0] << std::endl;
// 	}
// }

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}