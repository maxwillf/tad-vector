#include <iostream>
#include "vector.tpp"

using namespace sc;

int main( void ){
	Vector<int> teste(10);
	std::cout << "\n\n";

	std::cout << teste.front() << std::endl;
	std::cout << teste.back() << std::endl;
	std::cout << teste.at(8) << std::endl;
	std::cout << teste[8] << std::endl;

	std::cout << "# TODO" << std::endl;

	std::cout << "\n\n";

	return 0;
}
