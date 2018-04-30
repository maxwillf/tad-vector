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
	Vector<int> teste( 10 );
	populate(teste);

    std::cout << "\n\n";

    std::cout << "> Antes:\n";
	printArray( teste, ' ' );

    // operations stay here

	teste = {{ 2, 2, 2, 2 }}; 	// why does only work with two braces?
								// (if only { ...numbers... }, will not work)

    // end of operations space

	std::cout << "> Depois:\n";
	printArray( teste, ' ' );

	std::cout << "\n\n";
	return 0;
}
