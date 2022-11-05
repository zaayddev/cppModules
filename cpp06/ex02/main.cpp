/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 19:07:24 by guhernan          #+#    #+#             */
/*   Updated: 2021/12/02 13:24:05 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <exception>

Base	*generate(void) {

	int randRtn = std::rand();

	if (randRtn % 3 == 0){
		std::cout << "Generate .... A !" << std::endl;
		return new A;
	}
	else if (randRtn % 2 == 0){
		std::cout << "Generate .... B !" << std::endl;
		return new B;
	}
	std::cout << "Generate .... C !" << std::endl;
	return new C;
}

void	identify(Base *p) {
	if (p == NULL)
		return ;
	if (dynamic_cast<A *>(p))
		std::cout << "BRRRRRRRRRR [IDENTIFYER POINTER SELECTED : A] BRRRRRRRRR" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "BRRRRRRRRRR [IDENTIFYER POINTER SELECTED : B] BRRRRRRRRR" << std::endl;
	else if(dynamic_cast<C *>(p))
		std::cout << "BRRRRRRRRRR [IDENTIFYER POINTER SELECTED : C] BRRRRRRRRR" << std::endl;
}

void	identify(Base &p) {

	try {
		A &temp = dynamic_cast<A &>(p);
		std::cout << "BRRRRRRRRRR [IDENTIFYER REFERENCE SELECTED : A] BRRRRRRRRR" << std::endl;
		(void)temp;
	}
	catch (std::exception &e) {
	}

	try {
		B &temp = dynamic_cast<B &>(p);
		std::cout << "BRRRRRRRRRR [IDENTIFYER REFERENCE SELECTED : B] BRRRRRRRRR" << std::endl;
		(void)temp;
	}
	catch (std::exception &e) {
	}

	try {
		C &temp = dynamic_cast<C &>(p);
		std::cout << "BRRRRRRRRRR [IDENTIFYER REFERENCE SELECTED : C] BRRRRRRRRR" << std::endl;
		(void)temp;
	}
	catch (std::exception &e) {
	}
}

int		main() {

	std::srand(std::time(NULL));

	Base	*bOne = generate();
	Base	*bTwo = generate();
	Base	*bThree = generate();

	identify(*bOne);
	identify(bOne);
	identify(*bTwo);
	identify(bTwo);
	identify(*bThree);
	identify(bThree);

	delete bOne;
	delete bTwo;
	delete bThree;

}

