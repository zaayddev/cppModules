/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:49:52 by amorion-          #+#    #+#             */
/*   Updated: 2022/06/25 11:05:59 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casts.hpp"

void    disp_specd(char *argv)
{
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: " << argv << "f\n";
    std::cout << "double: " << argv << std::endl;
}

void    disp_double(char *argv)
{
    double	d = atof(argv);
    char	c = static_cast<char>(d);
    int		n = static_cast<int>(d);
    float	f = static_cast<float>(d);

    if(!ft_isascii(n))
        std::cout << "char: impossible\n";
    else if(!isprint(n))
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: \'" << c << "\'\n";
    if (d > INT_MAX || d < INT_MIN)
        std::cout << "int: imppossible\n";
    else
        std::cout << "int: "  << n << std::endl;
    std::cout.precision(1);
    std::cout << "float: " << std::fixed << f  << "f\n";
    std::cout << "double: " << std::fixed << d << std::endl;
}


bool    is_double(char *argv)
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
    if(!argv[i])
	{
		disp_double(argv);
		return(1);
	}
    if(!ft_strncmp(&argv[flag], "nan", ft_strlen(&argv[flag]))
            || !ft_strncmp(&argv[flag], "+inf", ft_strlen(&argv[flag]))
            || !ft_strncmp(&argv[flag], "-inf", ft_strlen(&argv[flag])))
    {
        disp_specd(&argv[flag]);
        return(1);
    }
    return(0);
}

