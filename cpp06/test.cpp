#include <iostream>

int main()
{
   const char* valueC = "42.224444444444444";
   float valueI = static_cast<float>(std::strtod(valueC, NULL));

   std::cout << valueC << " " << valueI << std::endl;
}