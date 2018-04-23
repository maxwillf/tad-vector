#include <iostream>
#include "vector.hpp"

using namespace sc;

int main( void ){
	Vector<int> teste(10);
    Vector<int> teste2(10);
    Vector<int> teste3(10);

	int a = 5;
	std::cout << "\n\n";

	// std::cout << teste.front() << std::endl;
	// std::cout << teste.back() << std::endl;
	// std::cout << teste.at(8) << std::endl;
	// std::cout << teste[8] << std::endl;
	std::cout << "old size: " <<  teste.size() << std::endl;
	std::cout << "old capacity: " << teste.capacity() << std::endl;
	for (int i = 0; i < 9; ++i) {
		teste.push_back(a);
	}
	std::cout << std::endl;
    std::cout << "Print teste:" << std::endl;
	for (int i = 0; i < teste.size(); ++i) {
		std::cout << teste[i] << " ";
	}
    std::cout << std::endl;

    std::cout << "Teste iterator" << std::endl;
    for( auto i = teste.begin(); i != teste.end(); i++ ){
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    std::cout << "Com novo for: " << std::endl;
    for ( auto &i : teste ){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << (teste3 == teste2 ? "São iguais" : "Não são iguais") << std::endl;

	std::cout << std::endl;
	std::cout << "new size: " << teste.size() << std::endl;
	std::cout << "new capacity: " << teste.capacity() << std::endl;
	std::cout << "# TODO" << std::endl;

	std::cout << "\n\n";

	return 0;
}
