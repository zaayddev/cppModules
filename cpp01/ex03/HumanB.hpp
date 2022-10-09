#ifndef HumanA_HPP
# define HumanA_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
    public:
        HumanB(std::string name);
        ~HumanB();
        std::string getName();
        void setName(std::string name);
        void setWeapon(Weapon &weapon);
        void attack();
    private:
        std::string name;
        Weapon *weapon;
};

#endif