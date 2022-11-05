/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:53:51 by amorion-          #+#    #+#             */
/*   Updated: 2022/06/25 11:05:57 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"casts.hpp"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Incorrect number of arguments" << std::endl;
		return(1);
	}
	if (is_char(argv[1]))
		return(0);
	if(is_int(argv[1]))
		return(0);
	if(is_double(argv[1]))
		return(0);
	if(is_float(argv[1]))
		return(0);
	else
		std::cout << "char: impossible\n" << "int: impossible\n"
			<< "float: impossible\n" << "double: impossible\n"; 
	return(0);
}
