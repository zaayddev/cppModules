#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
    private:
        unsigned int _n_ideas;
        std::string _ideas[100];

    public:
        Brain();
        Brain(const Brain& other);

        ~Brain();

        Brain& operator=(const Brain& other);

        std::string     getIdea(unsigned int x) const;
        unsigned int    getNIdea() const;
        void            setIdea(std::string idea);

};

#endif