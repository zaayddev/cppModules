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
#include <stack>

template<typename T, typename Container = std::deque<T> >
class	MutantStack : public std::stack<T, Container>
{
	public:

		MutantStack(void) {};
		MutantStack(MutantStack const &src) : MutantStack<T, Container>::stack(src) {};
		~MutantStack(void) {};

		MutantStack	&operator=(MutantStack const &rhs) {
			this->MutantStack::stack::operator=(rhs);
			return (*this);
		}

		typedef typename Container::iterator			iterator;
		iterator	begin(void) {
			return (this->c.begin());
		}

		iterator	end(void) {
			return (this->c.end());
		}
};
