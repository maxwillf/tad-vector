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
	populate(teste);

    // just a pretty print
    std::cout << "\n\n";

    std::cout << "Antes:\n";
	printArray( teste, ' ' );

    // operations stay here


    // end of operations space


	std::cout << "\n\n";
	return 0;
}
