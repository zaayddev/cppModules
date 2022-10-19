#include "Fixed.hpp"
#include "Point.hpp"

int main() {

	Point P2(Fixed(4.18f), Fixed(3.02f));
	Point P4(Fixed(94.16f), Fixed(100.12f));
	
    Point Pa(5.12, 4.16);
    Point Pb(1.18, -6.49);
	Point Pc(0, 0);


	// Inside
	std::cout << "BSP Return value: " << bsp(Pa, Pb, Pc, P2) << std::endl;
	

	// Outside
	std::cout << "BSP Return value: " << bsp(Pa, Pb, Pc, P4) << std::endl;

	return 0; 
}