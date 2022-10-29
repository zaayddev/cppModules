#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class	Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat(void);

		Bureaucrat	&operator=(Bureaucrat const &rhs);

		std::string const	getName() const;
		int					getGrade() const;

		void	incrGrade();
		void	decrGrade();

		class	GradeTooHighException : public std::exception
		{
			public:
				const char	*what() const throw()
				{
					return ("Grade too high!");
				}
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				const char	*what() const throw()
				{
					return ("Grade too low!");
				}
		};
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif