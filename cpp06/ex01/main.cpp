/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guhernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:02:25 by guhernan          #+#    #+#             */
/*   Updated: 2021/11/30 17:17:38 by guhernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

struct	Data	{
	unsigned int	number;
};

uintptr_t	serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data		*deserialize(uintptr_t raw){
	return reinterpret_cast<Data *>(raw);
}

int	main() {

	Data	*test = new Data;
	test->number = 101;
	std::cout << test << std::endl;
	std::cout << test->number << std::endl << std::endl;

	uintptr_t buffer = serialize(test);
	std::cout << "Serialization of Data *" << std::endl << std::endl;

	Data	*outPut = deserialize(buffer);
	std::cout << outPut << std::endl;
	std::cout << outPut->number << std::endl;

	delete test;
}
