#include "Zombie.hpp"

int main(void) {
    Zombie nameless;
        nameless.set_name("Ted Bundy");
        nameless.announce();

    Zombie *bob = newZombie("Richard Ramirez");

    randomChump("John Wayne Gacy");

    delete bob;
    return (0);
}