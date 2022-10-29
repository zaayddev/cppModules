/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchbani <zchbani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:49:30 by ysachiko          #+#    #+#             */
/*   Updated: 2022/10/29 21:00:01 by zchbani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat chip("Chip", 1);
		std::cout << chip << std::endl;
		chip.decrGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
