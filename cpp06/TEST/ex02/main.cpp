/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:07:13 by amorion-          #+#    #+#             */
/*   Updated: 2022/06/25 12:19:24 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdlib.h>
#include <iostream>
#include <time.h>
Base * generate(void)
{
	srand(time(NULL));

    switch(rand() % 3)
    {
		case(0):
            return(new A);
		case(1):
            return(new B);
		case(2):
            return(new C);
		default :
			return(new Base);
    }
}

void identify(Base *p)
{
    if(dynamic_cast<A*>(p))
        std::cout << "Class A\n";
    else if(dynamic_cast<B*>(p))
        std::cout << "Class B\n";
    else if(dynamic_cast<C*>(p))
        std::cout << "Class C\n";
    else
        std::cout << "Not A B C\n";
}

int main(void)
{
	Base *b = generate();
	identify(b);
	delete b;
	return(0);
}
