#include "Data.hpp"

int main()
{
    Data data1 = {30};
    std::cout << "value of data1 : ";
    std::cout << data1.n << '\n';
    std::cout << "address of data1 : ";
    std::cout << &(data1) << '\n';
    uintptr_t seria = serialize(&data1);
    std::cout << "takes a pointer and converts it to the unsigned integer type uintptr_t : ";
    std::cout << seria << '\n';
    Data *deseria = deserialize(seria);
    std::cout << "takes an unsigned integer parameter and converts it to a pointer to Data: ";
    std::cout << deseria->n << '\n';
}