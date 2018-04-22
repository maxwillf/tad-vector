#ifndef VECTOR_HPP_
#define VECTOR_HPP_
#define debug true
#include <iostream>
#include <math.h>
#include <algorithm>
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
    size_type m_capacity;
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
    size_type size() const; // Returns amount of the vector's initialized elements
    size_type capacity( void ) const; // Returns amount of memory allocated for the vector
    void reserve( size_type new_cap ); // If new_cap > capacity allocates (new_cap - capacity) bytes

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

	/* fazendo as mudanças necessárias para o uso de capacity */

	Vector<T>::Vector( int size ){
    int temp_capacity;
    if(size > 2){

      int temp_log = log2(size);
      int int_temp_log = int(temp_log);

      temp_capacity = pow(2,int_temp_log); /* A capacidade tem que estar sempre em expoentes de 2
                                              como recomendado em sala de aula */
      if(size > temp_capacity){
        temp_capacity *= 2;
      }
    }
    else {
      temp_capacity = size;
    }
    // alocating [size] elements of type T
    this->elements = new T[temp_capacity];
    for( int i = 0; i < size; i++ ){
      elements[i] = i; 		// Inicializador não padrão
    }
    this->m_first = elements;
    this->m_last = elements + size;
    this->m_size = size;
    this->m_capacity = temp_capacity;
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

  /*! Returns the amount of elements in the vector */
	template <class T>
	size_type Vector<T>::size() const {
	
    return this->m_size;

	}
  /*! Returns the maximum amount of elements for current allocated size */
  template <class T>
  size_type Vector<T>::capacity( void ) const{

    return this->m_capacity;
  }
  /*! Allocates memory if new_cap > capacity
    \param new_cap expected size of the array after function call
  */
	template <class T>
	void Vector<T>::reserve(size_type new_cap){

    if(new_cap > m_capacity){

      m_capacity = new_cap;
      T *temp_elements = new T[m_capacity];
      std::copy(elements,m_last,temp_elements);
      delete [] elements;
      elements = temp_elements;
    }

	}

	template <class T>
	void Vector<T>::push_back( const T& value ){
	
    if(m_size < m_capacity){

      *m_last++ = value;
      m_size += 1;
    }

    else {
      this->reserve(m_capacity*2);	
      m_size += 1;
      m_first = elements;
      m_last = elements + m_size-1;
      *m_last++ = value;
    }
       

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
