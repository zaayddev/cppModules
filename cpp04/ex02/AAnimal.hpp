#ifndef AAnimal_HPP
# define AAnimal_HPP

# include <iostream>

class AAnimal
{
    protected:
        std::string _type;

    public:
        AAnimal();
        AAnimal(std::string type);
        AAnimal(const AAnimal& other);

        virtual ~AAnimal();

        virtual AAnimal& operator=(const AAnimal& other);

        std::string getType() const;

        virtual void makeSound() const = 0;
        virtual void thoughts() const = 0;
};

#endif