#ifndef HumanB_HPP
# define HumanB_HPP

#include <string>
#include "Weapon.hpp"

class HumanA {
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA();
        std::string getName();
        void setName(std::string name);
        void setWeapon(Weapon &weapon);
        void attack();
    private:
        std::string name;
        Weapon &weapon;
};

#endif