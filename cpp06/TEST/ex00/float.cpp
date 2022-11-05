/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 09:21:43 by amorion-          #+#    #+#             */
/*   Updated: 2022/06/25 10:59:55 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casts.hpp"

void	disp_float(char *argv)
{
	float	f = atof(argv);
	char 	c = static_cast<char>(f);
	int		n = static_cast<int>(f);
	double	d = static_cast<double>(f);
	
	if(!ft_isascii(n))
        std::cout << "char: impossible\n";
    else if(!isprint(n))
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: \'" << c << "\'\n";
	if (f > INT_MAX || f < INT_MIN)
		std::cout << "int: imppossible\n";
	else
		std::cout << "int: "  << n << std::endl;
	std::cout.precision(1);
	std::cout << "float: " << std::fixed << f  << "f\n";
	std::cout << "double: " << std::fixed << d << std::endl;
}

void	disp_specf(char *argv)
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: " << argv << std::endl;
	char *d = argv;
	d[ft_strlen(d) - 1] = 0;
	std::cout << "double: " << d << std::endl;
}

bool	is_float(char *argv)
{
	 int i = 0;
	 int point = 0;
	 int flag = 0;
    while(argv[i] && isspace(argv[i]))
        i++;
	flag = i;
    if(argv[i] == '+' || argv[i] == '-')
        i++;
    while(argv[i])
    {
		if(isdigit(argv[i]) || (argv[i] == '.' && !point))
		{
			if(argv[i] == '.')
				point++;
			i++;
		}
		else
			break;
	}
    if(argv[i] == 'f' && !argv[i + 1])
	{
		disp_float(argv);
		return(1);
	}
	if(!ft_strncmp(&argv[flag], "nanf", ft_strlen(&argv[flag]))
			|| !ft_strncmp(&argv[flag], "+inff", ft_strlen(&argv[flag]))
			|| !ft_strncmp(&argv[flag], "-inff", ft_strlen(&argv[flag])))
	{
		disp_specf(&argv[flag]);
		return(1);
	}
	return(0);
}
