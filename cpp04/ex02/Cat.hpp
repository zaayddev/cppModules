#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal {
    private:
        Brain* _brain;

    public:
        Cat();
        Cat(const Cat& other);

        virtual ~Cat();

        Cat& operator=(const Cat& other);

        Brain* getBrain() const;

        void makeSound() const;
        void thoughts() const;
};

#endif