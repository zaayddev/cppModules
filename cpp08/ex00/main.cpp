#include "easyfind.hpp"
#include <iterator>
#include <array>
#include <vector>
#include <list>

int main() {
    {
        std::array<int, 5> arr = {10, 20, 30, 40, 50};
        std::array<int, 5>::iterator it;

        std::cout << "array: [ ";
        for (it = arr.begin(); it != arr.end(); it++) {
            std::cout << *it << " ";
        }
        std::cout << "]" << std::endl;
        try {
            it = easyfind(arr, 10);
            std::cout << *it << std::endl;
            it = easyfind(arr, 84);
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    {
        std::vector<int> vect;
        std::vector<int>::iterator it;

        std::cout << "vector: [ ";
        for (int i = 1; i <= 5; i++) {
            vect.push_back(i * 10);
        }
        for (it = vect.begin(); it != vect.end(); it++)
            std::cout << *it << " ";
        std::cout << "]" << std::endl;
        try {
            it = easyfind(vect, 50);
            std::cout << *it << std::endl;
            it = easyfind(vect, 84);
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    {
        std::list<int> list;
        std::list<int>::iterator	it;
        std::cout << std::endl << "list: [ ";
        for (int f = 1; f <= 5; f++)
            list.push_back(f * 10);
        for (it = list.begin(); it != list.end(); it++)
            std::cout << *it << " ";
        std::cout << "]" << std::endl;
        try {
            it = easyfind(list, 10);
            std::cout << *it << std::endl;
            it = easyfind(list, 80);
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
}