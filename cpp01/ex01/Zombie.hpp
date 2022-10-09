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

Zombie *zombieHorde(int N, std::string name);

#endif