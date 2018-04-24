#include <iostream>
#include <random>
#include <chrono>
#include "vector.hpp"

using namespace sc;

// Debugging function
template <class T>
void printArray( T *first, T *last, char sep ){
    for( T *i = first; i < last; i++ ){
        std::cout << *i << sep;
    }
    std::cout << std::endl;
}

template <class T>
void populate( Vector<T> &V ){
    for( T *i = V.begin(); i < V.end(); i++ ){
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 rd (seed);
        *i = rd() % 99 + 9;
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
    printArray( teste.begin(), teste.end(), ' ' );
    printArray( teste2.begin(), teste2.end(), ' ' );

    // operations stay here

    teste = teste2;
    // teste2 = teste;

    // end of operations space

    std::cout << "Depois:\n";
    printArray( teste.begin(), teste.end(), ' ' );
    printArray( teste2.begin(), teste2.end(), ' ' );

	std::cout << "\n\n";

	return 0;
}
