#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
    protected:
        std::string _type;

    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal& other);

        virtual ~Animal();

        Animal& operator=(const Animal& other);

        std::string getType() const;

        virtual void makeSound() const;
};

#endif