#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string.h>
#include <iostream>

class Zombie {
   public:
      Zombie();
      ~Zombie();
      std::string get_name();
      void set_name(std::string name);
      void announce();
   private:
      std::string name;
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif