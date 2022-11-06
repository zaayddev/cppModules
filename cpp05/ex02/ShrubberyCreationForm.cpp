#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), _target("Default") {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), _target(target) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : Form("ShrubberyCreationForm", 145, 137) {
	*this = src;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
	if (this != &src)
		this->_target = src.getTarget();
	return *this;
}

const std::string &ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (this->getSign() && executor.getGrade() <= this->getExec()) {
		std::cout << "Creating Shrubbery Form" << std::endl;
		std::ofstream file(this->getTarget() + "_shrubbery");
		if (!file.good()) {
			std::cout << "Can't open the file" << std::endl;
			return;
		}
		file << "ASCII TREE" << std::endl;
		file << "                                                         .\n";
		file << "                                              .         ;\n";  
		file << "                 .              .              ;%     ;;\n";   
		file << "                   ,                           :;%  %;\n";   
		file << "                    :         ;                   :;%;'     .,\n";   
		file << "           ,.        %;     %;            ;        %;'    ,;\n";
		file << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
		file << "             %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"; 
		file << "              ;%;      %;        ;%;        % ;%;  ,%;'\n";
		file << "                `%;.     ;%;     %;'         `;%%;.%;'\n";
		file << "                 `:;%.    ;%%. %@;        %; ;@%;%'\n";
		file << "                    `:%;.  :;bd%;          %;@%;'\n";
		file << "                      `@%:.  :;%.         ;@@%;'\n";   
		file << "                        `@%.  `;@%.      ;@@%;\n";         
		file << "                          `@%%. `@%%    ;@@%;\n";        
		file << "                            ;@%. :@%%  %@@%;\n";       
		file << "                              %@bd%%%bd%%:;\n";     
		file << "                                #@%%%%%:;;\n";
		file << "                                %@@%%%::;\n";
		file << "                                %@@@%(o);  . '\n";        
		file << "                                %@@@o%;:(.,'\n";         
		file << "                            `.. %@@@o%::;\n";         
		file << "                               `)@@@o%::;\n";         
		file << "                                %@@(o)::;\n";        
		file << "                               .%@@@@%::;\n";         
		file << "                               ;%@@@@%::;.\n";          
		file << "                              ;%@@@@%%:;;;.\n"; 
		file << "                          ...;%@@@@@%%:;;;;,..\n";
		file.close();
	}
	else
		throw Form::GradeTooLow();
}
