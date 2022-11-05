#include "Convert.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "[ERROR]: Invalid number of arguments!" << std::endl;
        return (1);
    }
    try
    {
        std::string arg = argv[1];
        Convert     in(arg);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}