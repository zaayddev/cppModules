// The simple idea of a template is to pass data type as a parameter
// so that we don’t need to write the same code for different data types.
#include "Wathever.hpp"
#include <iostream>
  
int main( void )
{
   int a = 2;
   int b = 4;
   ::swap( a, b );
   std::cout << "a = " << a << ", b = " << b << std::endl;
   std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
   std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
   std::string c = "chaine1";
   std::string d = "chaine2";
   ::swap(c, d);
   std::cout << "c = " << c << ", d = " << d << std::endl;
   std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
   std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
   return 0;
}
