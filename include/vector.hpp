#ifndef VECTOR_HPP_
#define VECTOR_HPP_
#define debug true

#include <iostream>

/*!
 * \file vector.hpp
 * \author Felipe Ramos
 */
using size_type = size_t;
/*!
 * \brief A class that stores all vector functions
 */
namespace sc
{
	template <class T>
	class Vector{
		// As funções comentadas já foram implementadas.
		private:
			T *m_first;					// an 'first' pointer
			T *m_last;					// an 'last' pointer
			T *elements;				// where the array will be stored
			size_type m_size = 0;		// default empty array
		public:
			// special members
			Vector( int );				// Default constructor
			~Vector( void );			// Default destructor

			// iterator methods
			T &begin();
			T &end();
			T &cbegin();
			T &cend();

			// capacity methods
			bool empty( void );
			size_type size() const;
			size_type capacity( void ) const;
			void reserve( size_type new_cap );

			// modifiers methods
			void clear( void );
			void push_front( const T & );
			void push_back( const T & );
			void pop_front( void );
			void pop_back( void );
			void insert( T & );
			void shrink_to_fit();
			void assign( const T &value );
			void erase();

			// element acess methods
			const T &front() const; 	// Acess front member (first member)
			const T &back() const;		// Acess back member (last member)
			T &at( size_type pos );		// Acess [pos] element at the datatype

			// operators
			T &operator=( const T & );		// Copy content from another object
			bool operator==( const Vector & );
			// bool operator!=( const vector&, const vector & ); // check it
			T &operator[]( size_type pos ); 	// Access [pos] element by doing
												// object[pos]
	};

	// implementation

	template <class T>
	Vector<T>::Vector( int size ){
		// alocating [size] elements of type T		
		this->elements = new T[size];
		for( int i = 0; i < size; i++ ){
			elements[i] = i; 		// Inicializador não padrão
		}
		this->m_first = elements;
		this->m_last = elements + size;
		this->m_size = size;
		if(debug) std::cout << "> Vector allocated with sucess!" << std::endl;
	}

	template <class T>
	Vector<T>::~Vector( void ){
		delete[] elements;
		// delete m_first; 		// Descobrir pq não rola
		// delete m_last; 		// Descobrir pq não rola
		if(debug) std::cout << "> Vector deleted with sucess!" << std::endl;
	}

	template <class T>
	const T &Vector<T>::front() const{
		return *(this->m_first);
	}

	template <class T>
	const T &Vector<T>::back() const{
		T *valid_l = this->m_last - 1;
		return *valid_l;
	}

	template <class T>
	T &Vector<T>::at( size_type pos ){
		return (this->elements[pos]);
	}

	template <class T>
	T &Vector<T>::operator[]( size_type pos ){
		return this->elements[pos];	
	}

	template <class T>
	T &Vector<T>::operator=( const T &rhs ){
		// TODO: We need to make size() functions ready
	}

}


#endif
