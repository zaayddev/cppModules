            /*:::      ::::::::
             :+:      :+:    :+:
           +:+ +:+         +:+
         +#+  +:+       +#+ 
       +#+#+#+#+#+   +#+
          #+#    #+#      
         ###   ########  zchbani*/
#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <exception>
#include <numeric>

class Span
{
    private:
        unsigned int        _size;
        std::vector<int>    _vector;

    public:
        Span();
        Span(unsigned int N);
        Span(Span const &src);
        ~Span();
        Span    &operator=(Span const &rhs);

        void    		addNumber(int n);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);
        void            fillVectorNumber(unsigned int n);
    	void 			print();

        class	VectorFullException : public std::exception
		{
			public:
				const char	*what() const throw();
		};

		class	NotEnoughNumbersException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};
