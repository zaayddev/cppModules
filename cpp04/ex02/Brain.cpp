#include "Brain.hpp"

Brain::Brain() : _n_ideas(0) {
    std::cout << "Brain default constructor called" << std::endl;
    return ;
}

Brain::Brain(const Brain& other) {
    std::cout << "Brain copy constructor called" << std::endl;
    *this = other;
    return ;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
    return ;
}

Brain& Brain::operator=(const Brain& other) {
	unsigned int	i;

	std::cout << "Brain assignment operator called." << std::endl;
	if (this != &other)
	{
		this->_n_ideas = other.getNIdea();
		i = -1;
		while (++i < this->_n_ideas)
			this->_ideas[i] = other.getIdea(i);
	}
	return (*this);
}

std::string Brain::getIdea(unsigned int x) const {
    if (x >= this->_n_ideas)
        return ("No idea at this index");
    return (this->_ideas[x]);
}

unsigned int Brain::getNIdea() const {
    return (this->_n_ideas);
}

void Brain::setIdea(std::string idea) {
    if (this->_n_ideas == 100)
        return ;
    this->_ideas[this->_n_ideas] = idea;
    this->_n_ideas++;
    return ;
}

