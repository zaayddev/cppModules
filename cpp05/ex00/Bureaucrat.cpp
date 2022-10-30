#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(LOW){
	std::cout << "Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name), grade(_grade){
	std::cout << "Constructor called" << std::endl;
	if (_grade < HIGH)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > LOW)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name(src.name) {
	std::cout << "Copy Constructor called" << std::endl;
	*this = src;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Destructor called" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &src) {
	std::cout << "Assignment operator called" << std::endl;
	if (this != &src) {
		this->grade = src.grade;
		//const_cast<std::string&>(name) = src.name;
	}
	return *this;
}

std::string Bureaucrat::getName() const {
	return this->name;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::incrGrade() {
	this->grade--;
	if (this->grade < HIGH)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrGrade() {
	this->grade++;
	if (this->grade > LOW)
		throw Bureaucrat::GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &src) {
	o << src.getName() << ", bureaucrat grade " << src.getGrade();
	return o;
}
