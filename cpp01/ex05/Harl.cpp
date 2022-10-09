#include "Harl.hpp"

void Harl::complain(std::string level) {
    void (Harl::*functions[5])(void) = {
        &Harl::ft_error,
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    int index = (
        (level == "DEBUG") * 1 
        + (level == "INFO") * 2
        + (level == "WARNING") * 3
        + (level == "ERROR") * 4);
    (this->*functions[index])();
}

void Harl::debug() {
    std::cout
    << "I love having extra bacon for my "
    "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
    << std::endl;
}

void Harl::info() {
    std::cout
    << "I cannot believe adding extra bacon costs more money. You didn’t put "
    "enough bacon in my burger! If you did, I wouldn’t be asking for more!"
    << std::endl;
}

void Harl::warning() {
    std::cout
    << "I think I deserve to have some extra bacon for free. I’ve been "
    "coming for years whereas you started working here since last month."
    << std::endl;
}

void Harl::error() {
    std::cout 
	<< "This is unacceptable! I want to speak to the manager now."
    << std::endl;
}

void Harl::ft_error() {
    std::cout << "No matching level!" << std::endl;
}