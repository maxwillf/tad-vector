#include <iostream>
#include <random>
#include <chrono>
#include "vector.hpp"
#include <vector>

/* Client code functions {{{*/
namespace client
{
	// Here, all the client-side functions are defined
	// Simple array printer
	template <class T>
		void print_it( sc::Vector<T> &V, char sep ){
			for( auto it = V.begin(); it != V.end(); ++it ){
				std::cout << *it << sep;
			}
			std::cout << std::endl;
		}

	template <class T>
		void print_it_vec( std::vector<T> &V, char sep ){
			for( auto it = V.begin(); it != V.end(); ++it ){
				std::cout << *it << sep;
			}
			std::cout << std::endl;
		}

	// Populate a given array with random values between [0, 1000)
	template <class T>
		void populate( sc::Vector<T> &V ){
			for( auto it = V.begin(); it != V.end(); ++it ){
				auto seed = 
					std::chrono::system_clock::now().time_since_epoch().count();
				std::mt19937 rd (seed);
				*it = rd() % 1000;
			}
		}
}
/*}}}*/

/* Styles functions {{{*/
namespace h{
	void sep( void ){
		for( int i = 0; i < 80; i++ )
			std::cout << "-";
		std::cout << std::endl;
	}

	void h1(std::string phrase){
		std::cout << "\e[1m";
		std::cout << "~ " << phrase;
		std::cout << "\e[0m" << std::endl;
	}
	
	void h2(std::string phrase){
		std::cout << "\n> ";
		std::cout << phrase << std::endl;
	}
}
/*}}}*/

int main( void ){

	/* Special members tests {{{*/
	{
		h::h1("Special members tests");

		{	h::h2("Empty constructor");
			
			// Declaration
			sc::Vector<int> EmptyVector; 
			std::cout << "EmptyVector object created!\n";

			// Populating
			std::cout << "Populating EmptyVector with push_back()...\n";
			for( int i = 0; i < 10; i++ )
				EmptyVector.push_back(i);

			// Simple print the object
			std::cout << "EmptyVector elements: ";
			client::print_it(EmptyVector, ' ');
		}

		{	h::h2("Constructor with pre-defined size");

			// Declaration
			sc::Vector<int> SizeVector(10);

			// Populating
			std::cout << "Populating SizeVector with positive values...\n";
			for( int i = 0; i < 10; i++ )
				SizeVector[i] = i;

			// Simple print the object
			std::cout << "SizeVector elements: ";
			client::print_it( SizeVector, ' ' );
		}

		{	h::h2("Copy constructor from a simple array");

			// Declaration
			int Vet[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			sc::Vector<int> cVector( Vet, Vet+10 );

			// Simple print
			std::cout << "Copy vector elements: ";
			client::print_it( cVector, ' ' );
		}
		
		{	h::h2("Copy constructor from another sc::Vector");

			// Declaration
			sc::Vector<int> origVec(10);
			client::populate( origVec );
			sc::Vector<int> copyVec( origVec );

			// Simple print
			std::cout << "Copied vector elements: ";
			client::print_it( copyVec, ' ' );
		}
		h::sep();
	}
	/*}}}*/
	
	/* Capacity functions tests {{{*/
	{
		h::h1("Capacity functions tests");
		std::cout << "TESTS HERE...\n";
		h::sep();
	}
	/*}}}*/

	/* Modifiers functions tests {{{*/
	{
		h::h1("Modifiers functions tests");
		std::cout << "TESTS HERE...\n";
		h::sep();
	}
	/*}}}*/

	/* Element access functions tests {{{*/
	{
		h::h1("Element access functions tests");
		std::cout << "TESTS HERE...\n";
		h::sep();
	}
	/*}}}*/

	/* Operators tests {{{*/
	{
		h::h1("Operators tests");
		std::cout << "TESTS HERE...\n";
		h::sep();
	}
	/*}}}*/

	/* Iterators tests {{{*/
	{
		h::h1("Iterators tests");
		std::cout << "TESTS HERE...\n";
		h::sep();
	}
	/*}}}*/

	return 0;
}
