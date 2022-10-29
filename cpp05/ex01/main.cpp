/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysachiko <ysachiko@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:31:56 by ysachiko          #+#    #+#             */
/*   Updated: 2022/10/20 13:32:01 by ysachiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try {
		Form f1 = Form("M37", 10, 5);
		Bureaucrat b1 = Bureaucrat("Ash", 30);
		Bureaucrat b2 = Bureaucrat("Quad", 1);
		
		b1.signForm(f1);
		b2.signForm(f1);
		Form f2 = Form("C28", 0, 5);
		std::cout << "no line" << std::endl;
	}
	catch (std::exception & e) 
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}
