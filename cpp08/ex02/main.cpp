#include "MutantStack.hpp"
#include <list>

int main(void)
{
	std::stack<int> krisi;
	
	std::cout << std::string(60, '-') << std::endl;
	std::cout << "my own std::stack iterator container " << std::endl;
	{
		MutantStack<int> mystack;
		MutantStack<int> mystack2;
		mystack.push(8);
		mystack.push(12);
		std::cout << mystack.top() << std::endl;
		mystack.pop();
		std::cout << mystack.size() << std::endl;
		mystack.push(4);
		mystack.push(8);
		mystack.push(424);
		mystack.push(1);
		MutantStack<int>::iterator it = mystack.begin();
		MutantStack<int>::iterator ite = mystack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mystack);

		// mystack2 = mystack;
		// std::cout << std::string(60, '-') << "HERE" << std::endl;
		// std::cout << *mystack2.begin() << std::endl;
		// std::cout << *mystack.begin() << std::endl;
	}
	std::cout << std::string(60, '-') << std::endl;
	std::cout << "compare with the original library" << std::endl;
	{
		std::list<int> mystack2;
		mystack2.push_back(8);
		mystack2.push_back(12);
		std::cout << mystack2.back() << std::endl;
		mystack2.pop_back();
		std::cout << mystack2.size() << std::endl;
		mystack2.push_back(4);
		mystack2.push_back(8);
		mystack2.push_back(424);
		mystack2.push_back(1);
		std::list<int>::iterator it = mystack2.begin();
		std::list<int>::iterator ite = mystack2.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mystack2);
	}
	return 0;
}