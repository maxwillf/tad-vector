#ifndef VECTOR_HPP_
#define VECTOR_HPP_
#define debug false
#include <iostream>
#include <cmath>
#include <algorithm>

/*!
 * \file vector.hpp
 * \author Felipe Ramos & Max William
 */

using size_type = size_t; 

/*!
 * \brief A class that stores all vector functions
 */

namespace sc
{
	template <class T>
	class Vector{
	private:
		T *m_first;					// an 'first' pointer
		T *m_last;					// an 'last' pointer
		T *elements;				// where the array will be stored
		size_type m_size = 0;		// default empty array 
		size_type m_capacity;		// maximum capacity of the array
	public:
		// special members
		Vector( int );				// Default constructor
		~Vector();					// Default destructor


		// capacity methods
		bool empty();
		// Returns amount of the vector's initialized elements
		size_type size() const;
		// Returns amount of memory allocated for the vector
		size_type capacity() const;
		// If new_cap > capacity allocates (new_cap - capacity) bytes
		void reserve( size_type ); 

		// modifiers methods
		void clear();
		void push_front( const T & );
		void push_back( const T & );	// insert an element on last position
		void pop_front();
		void pop_back();
		void insert( T & );
		void shrink_to_fit();
		void assign( const T & );
		void erase();

		// element acess methods
		const T &front() const;		// Acess front member (first member)
		const T &back() const;		// Acess back member (last member)
		T &at( size_type pos );		// Acess [pos] element at the datatype

		// operators
		Vector &operator=( const Vector & );// Copy content from another object
		bool operator==( const Vector & );  // Checks if Vector1 == Vector2
		bool operator!=( const Vector & );  // Checks if Vector1 != Vector2
		T &operator[]( size_type );	 		// Access [pos] element by doing
											// object[pos]
		// template <class T>
		class iterator{
			public: 	// iterator traits
				typedef std::ptrdiff_t difference_type;
				typedef std::bidirectional_iterator_tag iterator_category;

				// constructors
				iterator( T* ptr=nullptr );
				iterator( const iterator & );
				// destructors
				~iterator( void );
				//operators
				iterator &operator=( const iterator &rhs ){
					this->m_ptr = rhs.m_ptr;
				}

				T &operator*( void ) const{
					return *this->m_ptr;
				}

				iterator operator++( void ){	// ++it
					return ++this->m_ptr;		
				}

				iterator operator++( int ){		// it++
					return this->m_ptr++;		
				}

				iterator operator--( void ){	// --it
					return --this->m_ptr;
				}

				iterator operator--( int ){
					return this->m_ptr--;
				}

				bool operator==( const iterator &rhs ){
					return this->m_ptr == rhs.m_ptr;
				}

				bool operator!=( const iterator &rhs ) const{
					return this->m_ptr != rhs.m_ptr;
				}

			private:
				T* m_ptr;
		};

		// iterator methods
		typename Vector<T>::iterator begin();
		typename Vector<T>::iterator end();
		typename Vector<T>::iterator cbegin() const;
		typename Vector<T>::iterator cend() const;

	};

}

// Where the implementation lives
#include "vector.inl"

#endif
