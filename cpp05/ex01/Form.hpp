#ifndef FORM_HPP
# define FORM_HPP
# define HIGH 1
# define LOW 150

class Bureaucrat;
# include "Bureaucrat.hpp"

class Form
{	
	private:
		const std::string _name;
		bool _signed;
		const int _grade;
		const int _exec;

	public:
		Form();
		Form(std::string name, int grade, int exec);
		Form(const Form &src);
		~Form();

		Form &operator=(const Form &src);

		int getGrade() const;
		std::string getName() const;
		int getExec() const;
		bool getSign() const;
		void beSigned(const Bureaucrat &bureaucrat);
		
		class GradeTooHigh : public std::exception
		{
			public:
			const char *what() const throw();
		};
		
		class GradeTooLow : public std::exception
		{
			public:
			const char *what() const throw();
		};     
};

std::ostream &operator<<(std::ostream &out, const Form &src);

#endif
