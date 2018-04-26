#include <iostream>
#include <random>
#include <chrono>
#include "vector.hpp"

using namespace sc;

// Debugging function
template <class T>
void printArray( Vector<T> &V, char sep ){
	for( auto it = V.begin(); it != V.end(); ++it ){
		std::cout << *it << sep;
	}
    std::cout << std::endl;
}

template <class T>
void populate( Vector<T> &V ){
	for( auto it = V.begin(); it != V.end(); ++it ){
		unsigned seed;
		seed = std::chrono::system_clock::now().time_since_epoch().count();
		std::mt19937 rd (seed);
		*it = rd() % 99 + 9;
	}
}

int main( void ){
    // declaration
	Vector<int> teste(10);
    Vector<int> teste2(25);
    // generate pseudo-random numbers and populate the vectors
    populate(teste);
    populate(teste2);


    // just a pretty print
    std::cout << "\n\n";

    std::cout << "Antes:\n";
	printArray( teste, ' ' );
	printArray( teste2, ' ' );

    // operations stay here

	Vector<int> testeCopy(teste);
    teste = teste2;
    // teste2 = teste;

    // end of operations space

    std::cout << "Depois:\n";
	// printArray( teste, ' ' );
	// teste.erase(teste.begin(),teste.begin()+15);
	printArray( teste, ' ' );
	// std::cout << "Capacity before " << teste.capacity() << std::endl;
	// teste.shrink_to_fit();
	// std::cout << "Capacity after " << teste.capacity() << std::endl;
	printArray( teste2, ' ' );
	printArray( testeCopy, ',' );

	std::cout << "\n\n";
	// teste2.clear();
	// printArray(teste2, ' ');
	// teste2.push_back(1);
	// std::cout << "size before " << teste2.size() << std::endl;
	// printArray(teste2, ' ');
	// std::cout << "size after " << teste2.size() << std::endl ;
	return 0;
}
