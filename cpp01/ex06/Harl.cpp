#include "Harl.hpp"

void Harl::complain(std::string level) {
    void (Harl::*functions[4])(void) = {
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

    switch (index) {
        case 1:
            (this->*functions[0])();
        case 2:
            (this->*functions[1])();
        case 3:
            (this->*functions[2])();
        case 4:
            (this->*functions[3])();
            break;
        default:
            std::cout 
            << "[ Probably complaining about insignificant problems ]"
            << std::endl;
            break;
    }
}

void Harl::debug() {
    std::cout
    << "[ DEBUG ]"
    << "\n"
    << "I love having extra bacon for my "
    "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
    << "\n"
    << std::endl;
}

void Harl::info() {
    std::cout
    << "[ INFO ]"
    << "\n"
    << "I cannot believe adding extra bacon costs more money. You didn’t put "
    "enough bacon in my burger! If you did, I wouldn’t be asking for more!"
    << "\n"
    << std::endl;
}

void Harl::warning() {
    std::cout
    << "[ WARNING ]"
    << "\n"
    << "I think I deserve to have some extra bacon for free. I’ve been "
    "coming for years whereas you started working here since last month."
    << "\n"
    << std::endl;
}

void Harl::error() {
    std::cout
    << "[ ERROR ]"
    << "\n"
	<< "This is unacceptable! I want to speak to the manager now."
    << "\n"
    << std::endl;
}