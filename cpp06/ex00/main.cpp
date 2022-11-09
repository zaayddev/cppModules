/*  Converting an expression of a given type into another type 
    is known as type-casting
*/
#include "Conv.hpp"

int main(int ac, char **av)
{
    if (ac != 2 || (ac == 2 && !std::strlen(av[1])))
    {
        std::cout << "error; argument" << std::endl;
        return 1;
    }
    try
    {   
        Conv toConvert(av[1]);
        toConvert.printConv();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}