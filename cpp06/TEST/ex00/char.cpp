/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:38:10 by amorion-          #+#    #+#             */
/*   Updated: 2022/06/25 10:48:20 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casts.hpp"

bool is_char(char *argv)
{
	int i = 0;
	while (argv[i])
		i++;
	if (i > 1 || (argv[0] >= '0' && argv[0] <= '9'))
		return(0);
	char c = static_cast<char>(argv[0]);
	int n = static_cast<int>(argv[0]);
	float f = static_cast<float>(argv[0]);
	double d = static_cast<double>(argv[0]);
	std::cout << "char: \'" << c << "\'\n";
	std::cout << "int: " << n << std::endl;
	std::cout.precision(1);
    std::cout << "float: " << std::fixed << f  << "f\n";
    std::cout << "double: " << std::fixed << d << std::endl;
	return(1);

}
