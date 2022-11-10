            /*:::      ::::::::
             :+:      :+:    :+:
           +:+ +:+         +:+
         +#+  +:+       +#+ 
       +#+#+#+#+#+   +#+
          #+#    #+#      
         ###   ########  zchbani*/
#pragma once

#include <iostream>
#include <string>

class Exeption : public std::exception {
    public:
        const char *what() const throw() {
            return ("Can't find the number");
        }
};

template<typename T>
typename T::iterator easyfind(T &container, int tofind) {
    typename T::iterator it = container.begin();
    typename T::iterator ite = container.end();

    while (it != ite) {
        if (*it == tofind)
            return (it);
        it++;
    }
    throw(Exeption());
}