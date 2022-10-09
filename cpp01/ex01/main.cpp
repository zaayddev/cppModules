#include "Zombie.hpp"

int main(void) {
    Zombie *bob = zombieHorde(5, "Jeffrey Dahmer");
        delete [] bob;
    return (0);
}