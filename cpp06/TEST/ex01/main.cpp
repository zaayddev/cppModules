/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 11:25:20 by amorion-          #+#    #+#             */
/*   Updated: 2022/06/25 12:20:29 by amorion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

typedef struct s_Data{
	int x;
	char c;
	std::string s;
} Data;

uintptr_t	serialize(Data *ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data	*deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data *>(raw));
}

int main (void)
{
	Data d;
	d.x = 123;
	d.c = 'a';
	d.s = "Hello world";
	
	uintptr_t raw = serialize(&d);
	Data *fin = deserialize(raw);
	std::cout << "Before: " << &d  << std::endl;
	std::cout << "Serialized: " << raw << std::endl;
	std::cout << "Deserialized: " << fin << std::endl;
   	std::cout << "Last content: " << fin->x << " " << fin->c << " " << fin->s
		<< std::endl;
	return(0);	
}
