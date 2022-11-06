#include "Conv.hpp"

int main(int ac, char **av)
{
    if (ac != 2 || (ac == 2 && !std::strlen(av[1])))
    {
        std:: cout << "please provide one argument [ char ] or [ int ] or [ float ] or [ double ]" << std::endl;
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