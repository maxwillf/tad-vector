#include <iostream>
#include "vector.hpp"

using namespace sc;

int main( void ){
	Vector<int> teste(10);
    Vector<int> teste2(25);
    // Vector<int> teste3(10);

	// int a = 5;
    std::cout << "\n\n";

    std::cout << "Antes:\n";
    for ( auto &i : teste ){
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for ( auto &i : teste2 ){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    teste2[15] = 9109;

    // operator=();
    teste = teste2;

    std::cout << "Depois:\n";
    std::cout << &teste << std::endl;
    for ( auto &i : teste ){
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << &teste2 << std::endl;
    for ( auto &i : teste2 ){
        std::cout << i << " ";
    }
    std::cout << std::endl;

	std::cout << "\n\n";

	return 0;
}
