#ifndef VECTOR_HPP_
#define VECTOR_HPP_
#define debug true
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iterator> //for std::distance
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
	public:
		/* Class Iterator {{{*/
		class iterator{
			public:
				/* Public Code {{{*/
				typedef std::ptrdiff_t difference_type;
				typedef std::bidirectional_iterator_tag iterator_category;

				// constructors
				iterator( T* ptr=nullptr );
				iterator( const iterator & );

				// destructors
				~iterator( void );
				
				// operators 
				iterator &operator=( const iterator & );
				T &operator*( void ) const;

				iterator operator++( void );	// ++it
				iterator operator++( int );		// it++
				iterator operator--( void );	// --it
				iterator operator--( int );		// it--
				iterator operator-(int a ); // ptr-int
				iterator operator+(int a ); // ptr+int
//
				bool operator==( const iterator & ) const;
				bool operator!=( const iterator & ) const;
	
				int operator-(iterator rhs ); // ptr_diff
				
				/*}}}*/
			private:
				/* Private Code {{{*/
				T *m_ptr;
				/*}}}*/
		};
		/*}}}*/
		
		/* Iterator methods {{{*/
		typename Vector<T>::iterator begin();
		typename Vector<T>::iterator end();
		typename Vector<T>::iterator cbegin() const;
		typename Vector<T>::iterator cend() const;
		/*}}}*/
		private:

		T *m_first;					// an 'first' pointer
		T *m_last;					// an 'last' pointer
		T *elements;				// where the array will be stored
		size_type m_size = 0;		// default empty array 
		size_type m_capacity;		// maximum capacity of the array

	public:

		/* Special functions {{{*/
		Vector( int );				// Default constructor

		// TODO
		explicit Vector( size_type count );
		// template <class T>
		Vector( T *first, T *last );
		Vector( const Vector &other );			// Makes a deep copy of &other
		Vector( std::initializer_list<T> ilist ); // Already done
		// END OF TODO

		~Vector();					// Default destructor
		/*}}}*/

		/* Capacity functions {{{*/
		bool empty();

		// Returns amount of the vector's initialized elements
		size_type size() const;

		// Returns amount of memory allocated for the vector
		size_type capacity() const;

		// If new_cap > capacity allocates (new_cap - capacity) bytes
		void reserve( size_type ); 
		/*}}}*/

		/* Modifiers functions {{{*/
		/*! Deletes all elements from the vector */
		void clear();
		void push_front( const T & );
		void push_back( const T & );	// insert an element on last position
		void pop_front();
		void pop_back();
		void insert( T & );
		/*! Reduces Capacity according to the vector actual size */
		void shrink_to_fit();
		void assign( const T & );
		iterator erase(iterator pos); // Deletes element in position pos
		/*! Deletes elements in [first,last) */
		iterator erase(iterator first,iterator last);
		/* }}} */

		/* Element access functions {{{*/
		const T &front() const;		// Acess front member (first member)
		const T &back() const;		// Acess back member (last member)
		T &at( size_type pos );		// TODO Acess [pos] element at the datatype
		/*}}} */

		/* Operator functions {{{*/
		// Copy content from another object
		Vector &operator=( const Vector & );

		// Check syntax
		Vector &operator=( std::initializer_list<T> ilist );

		// Checks if Vector1 == Vector2
		bool operator==( const Vector & );

		// Checks if Vector1 != Vector2
		bool operator!=( const Vector & );  

		// Access [pos] element by doing object[pos]
		T &operator[]( size_type );	 		
		/*}}}*/

	};
}

// Source code 
#include "vector.inl"

#endif
