#include <iostream>

int main()
{
    {
        float a = 70.42f; 
        float *p1 = &a;
        std::cout << a << " " << &a <<std::endl;
        int *pI = reinterpret_cast<int *>(p1);
        std::cout << *pI << " " << pI << std::endl;
        float *pF = reinterpret_cast<float *>(pI);
        std::cout << *pF << " " << pF << std::endl;
    }
    std::cout << std::endl;
    {
        float a = 70.42f;
        std::cout << a << " " << &a <<std::endl;
        int pI = static_cast<int>(a);
        std::cout << pI << " " << &pI << std::endl;
        float pF = static_cast<float>(pI);
        std::cout << pF << " " << &pF <<std::endl;

    }
}