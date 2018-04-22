#include <iostream>
#include "vector.tpp"

using namespace sc;

int main( void ){
	Vector<int> teste(10);
	int a = 5;
	std::cout << "\n\n";

	std::cout << teste.front() << std::endl;
	std::cout << teste.back() << std::endl;
	std::cout << teste.at(8) << std::endl;
	std::cout << teste[8] << std::endl;
	std::cout << teste.size() << std::endl;
	std::cout << teste.capacity() << std::endl;
	for (int i = 0; i < 9; ++i) {
		teste.push_back(a);
	}
	std::cout << std::endl;
	for (int i = 0; i < teste.size(); ++i) {
		std::cout << teste[i] << std::endl;
	}
	std::cout << "# TODO" << std::endl;

	std::cout << "\n\n";

	return 0;
}
