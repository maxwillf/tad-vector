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
	auto it = teste.insert(teste.end(),999);
	std::cout << "teste iterator insert: " << *it << std::endl;
	printArray( teste, ' ' );
								// (if only { ...numbers... }, will not work)
	Vector<int> teste3 = {{ 1,2,3,4,5,6}};
	teste.push_front(5);
	printArray( teste, ' ' );
	teste.insert(teste.begin(),1337);
	printArray( teste, ' ' );
	 it =	teste.insert(teste.end(),111);
	std::cout << "teste iterator insert: " << *it << std::endl;
	printArray( teste, ' ' );
	it = teste.insert(teste.begin(),teste.begin(),teste.end());
	std::cout << "teste iterator insert: " << *it << std::endl;
	//printArray( teste, ' ' );
	//teste.insert(teste.begin()+3,teste3.begin(),teste3.begin()+2);
    // end of operations space

	std::cout << "> Depois:\n";
	printArray( teste, ' ' );

	std::cout << "\n\n";
	return 0;
}
