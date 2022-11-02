#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(LOW) {
	//std::cout << "Bureaucrat Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name), grade(_grade) {
	//std::cout << "Bureaucrat Constructor called" << std::endl;
	if (_grade < HIGH)
		throw Bureaucrat::GradeTooHighException();
	else if (_grade > LOW)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : name(src.name) {
	//std::cout << "Bureaucrat Copy Constructor called" << std::endl;
	*this = src;
}

Bureaucrat::~Bureaucrat(){
	//std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &src) {
	//std::cout << "Bureaucrat Assignment operator called" << std::endl;
	if (this != &src) {
		this->grade = src.grade;
		const_cast<std::string&>(name) = src.name;
	}
	return *this;
}

void Bureaucrat::signForm(Form &form) {
	if (form.getSign() == true)
		std::cout << "\033[0;36mYour form is already signed\033[0;37m" << std::endl;
	else
		try {
			form.beSigned(*this);
			std::cout << "\x1B[31m" << getName() << " signed " << form.getName() << "\033[0m" << std::endl; 
		}
		catch (std::exception &e) {
			std::cout << "\033[0;34m" << getName() << " couldn't sign " << form.getName();
			std::cout << e.what() << "\033[0m" << std::endl;
		}
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

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src) {
	out << src.getName() << ", bureaucrat grade " << src.getGrade();
	return out;
}
