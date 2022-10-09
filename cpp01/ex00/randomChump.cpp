#include "Zombie.hpp"

void randomChump(std::string name) {
    Zombie randomChump;
    randomChump.set_name(name);
    randomChump.announce();
}