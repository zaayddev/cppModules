/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casts.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:43:39 by amorion-          #+#    #+#             */
/*   Updated: 2022/06/25 11:04:22 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CASTS_HPP
# define CASTS_HPP
# include<iostream>
# include<climits>
# include<stdlib.h>

bool isspace(char c);
int	ft_isascii(int c);
int ft_isprint(int c);
int ft_isdigit(int c);
int ft_strncmp(char const *s1, char const *s2, int n);
int ft_strlen(char *str);

bool is_char(char *argv);
bool is_int(char *argv);
bool is_float(char *argv);
bool is_double(char *argv);
#endif
