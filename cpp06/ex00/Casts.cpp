#include "Casts.hpp"

Casts::Casts() {
	std::cout << "\e[0;33mDefault Constructor called of Casts\e[0m" << std::endl;
}

Casts::Casts(const Casts &copy) {
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Casts\e[0m" << std::endl;
}

Casts::~Casts() {
	std::cout << "\e[0;31mDestructor called of Casts\e[0m" << std::endl;
}

Casts & Casts::operator=(const Casts &assign) {
	(void) assign;
	return *this;
}

