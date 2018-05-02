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

		{	h::h2("Object construtor by std::initializer");
			
			// Declaration
			sc::Vector<int> initVec = { 1, 4, 3, 2, 5, 9, 10 };

			// Simple print
			std::cout << "Initializer Vector elements: ";
			client::print_it(initVec, ' ');
		}

		{	h::h2("Vector destructor");
			// Declaration
			sc::Vector<int> *V = new sc::Vector<int>;
			std::cout << "Vector allocated on " << V << std::endl;
			
			std::cout << "Trying to delete " << V << "..." << std::endl;
			delete V;
			std::cout << "Vector deleted with sucess!\n";
		}
		h::sep();
	}
	/*}}}*/
	
	/* Capacity functions tests {{{*/
	{
		h::h1("Capacity functions tests");
		{	h::h2("Empty method test");
			// Declaration
			sc::Vector<int> V(10);
			client::populate(V);
			std::cout << "created Vector V with 10 elements\n";
			sc::Vector<int> V_emp;	
			std::cout << "created Vector V_emp with 0 elements\n";

			// tests
			std::cout << "Is V empty? ";
			std::cout << ( V.empty() ? "Yes\n" : "No\n" );
			std::cout << "Is V_emp empty? ";
			std::cout << ( V_emp.empty() ? "Yes\n" : "No\n" );
		}

		{	h::h2("Size method test");
			// declaration
			sc::Vector<int> V(10);
			std::cout << "Vector V created\n";
			client::populate(V);
			std::cout << "Vector V has " << V.size() << " elements\n";

			sc::Vector<int> V2(40);
			std::cout << "Vector V2 created\n";
			client::populate(V2);
			std::cout << "Vector V2 has " << V2.size() << " elements\n";
		}
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
