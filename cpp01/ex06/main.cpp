#include "Harl.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "error; number of arguments" << std::endl;
        exit(EXIT_FAILURE);
    }
	Harl harl;
    harl.complain(argv[1]);
    return (EXIT_SUCCESS);
}