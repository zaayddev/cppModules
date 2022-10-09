#include "Zombie.hpp"

Zombie::Zombie() {}
Zombie::~Zombie() {
    std::cout << this->name << " doesn't exist." << std::endl;
}

std::string Zombie::get_name() {
     return this->name;
}

void Zombie::set_name(std::string name) {
    this->name = name;
}

void Zombie::announce(void) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}