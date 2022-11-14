#include "Span.hpp"

void Span::print() {
	std::cout << "[ ";
	std::copy(_vector.begin(), _vector.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "]" << std::endl;
}

int main(void)
{
	{
		try	{
			Span sp = Span(5);
			sp.addNumber(1);
			sp.addNumber(2);
			sp.addNumber(3);
			sp.addNumber(4);
			sp.addNumber(5);

			sp.print();

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan()  << std::endl;
		}
		catch (std::exception &exception) {
			std::cout << exception.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		try	{
			Span sp2 = Span(20000);
			sp2.fillVectorNumber(20000);

			//sp2.print();

			std::cout << sp2.shortestSpan() << std::endl;
			std::cout << sp2.longestSpan() << std::endl;
		}
		catch (std::exception &exception) {
			std::cout << exception.what() << std::endl;
		}
	}
}
