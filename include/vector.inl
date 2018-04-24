#include "vector.hpp"

namespace sc
{
	/* Special Member Block {{{*/

	/*!
	 * \brief Default constructor
	 * \param int size : Number of elements that the vector will have.
	 */
	template <class T>
	Vector<T>::Vector( int size ){
		int temp_capacity;
		if( size > 2 ){
			temp_capacity = pow( 2, log2(size) );	 // 2 ^ x growth
			if( size > temp_capacity ){
				temp_capacity *= 2;
			}
		} else {
			temp_capacity = size;
		}

		// alocating [size] elements of type T
		this->elements = new T[temp_capacity];
		for( int i = 0; i < size; i++ ){
			if(debug) elements[i] = i;			// debug inicializer
			else elements[i] = 0;				// normal inicializer
		}

		this->m_first = elements;
		this->m_last = elements + size;
		this->m_size = size;
		this->m_capacity = temp_capacity;

		if(debug) std::cout << "> Vector allocated with sucess!" << std::endl;
	}

	/*!
	 * \brief Default destructor
	 */
	template <class T>
	Vector<T>::~Vector(){
		if(elements != NULL){
			delete[] elements;
			if(debug) std::cout << "> Vector deleted with sucess!" << std::endl;
		}
	}
	/*}}}*/

	/* Capacity Methods {{{*/
	/*! Returns the amount of elements in the vector */
	template <class T>
	size_type Vector<T>::size() const {
		return this->m_size;
	}

	/*! Returns the maximum amount of elements for current allocated size */
	template <class T>
	size_type Vector<T>::capacity() const{
		return this->m_capacity;
	}

	/*! 
	 * \brief Allocates memory if new_cap > capacity
	 * \param new_cap expected size of the array after function call
	 */
	template <class T>
	void Vector<T>::reserve(size_type new_cap){
		if( new_cap > m_capacity ){
			m_capacity = new_cap;
			T *temp_elements = new T[m_capacity];
			std::copy( elements, m_last, temp_elements );
			delete [] elements;
			elements = temp_elements;
		}
	}
	/*}}}*/

	/* Modifiers Methods {{{*/

	template <class T>
	void Vector<T>::push_back( const T& value ){
		if( m_size < m_capacity ){
			*(m_last++) = value;
			m_size += 1;
		} else {
		this->reserve( m_capacity * 2 );	
			m_size += 1;
			m_first = elements;
			m_last = elements + m_size - 1;
			*(m_last++) = value;
		}
	} 

	/*}}}*/

	/* Elements Access Methods {{{*/

	/*!
	 * \brief Access the first element of the vector.
	 * \return The value of the first element of the vector (vector[0]).
	 */
	template <class T>
	const T &Vector<T>::front() const{
		return *(this->m_first);
	}

	/*!
	 * \brief Access the last element of the vector.
	 * \return The value of the last element of the vector (vector[size-1]).
	 */
	template <class T>
	const T &Vector<T>::back() const{
		T *valid_l = this->m_last - 1;
		return *valid_l;
	}
	
	/*!
	 * \brief Access element from a specified position
	 * \param size_type pos : User defined position
	 * \return Element at defined position
	 */
	template <class T>
	T &Vector<T>::at( size_type pos ){
		return ( this->elements[pos] );
	}

	/*}}}*/

	/* Operators Overloading {{{*/

	template <class T>
	T &Vector<T>::operator[]( size_type pos ){
		return this->elements[pos]; 
	}

	template <class T>
	Vector<T> &Vector<T>::operator=( const Vector<T> &rhs ){
		if( this->m_size < rhs.m_size ){
			this->reserve( rhs.m_size );
		}

		this->m_capacity = rhs.m_capacity;
		this->m_size = rhs.m_size;
		this->m_first = this->elements; 
		this->m_last = this->elements + m_size;

		for( int i = 0; i < rhs.m_size; i++ ){
			this->elements[i] = rhs.elements[i];
		}
		return *this;
	}

	template <class T>
	bool Vector<T>::operator==( const Vector &rhs ){
		if( rhs.m_size != this->m_size ){
			return false;
		} else {
			for( int i = 0; i < rhs.m_size ; i++ ){
				if( *(this->m_first+i) != *(rhs.m_first + i) ){
					return false;
				}
			}
		}
		// if he ever gets to this point, they're equal
		return true;
	}

	template <class T>
	bool Vector<T>::operator!=( const Vector &rhs ){
		if( this == rhs ){
			return false;
		} else {
			return true;
		}
	}
	/*}}}*/

	/* Vector Iterators {{{*/

	/*!
	 * \brief Begin iterator
	 * \return Iterator to the first element of the vector.
	 */
	template <class T>
	typename Vector<T>::iterator Vector<T>::begin(){
		return Vector<T>::iterator(this->m_first);
	}

	/*!
	 * \brief End iterator
	 * \return Iterator to the last element of the vector.
	 */
	template <class T>
	typename Vector<T>::iterator Vector<T>::end(){
		return this->m_last;
	}

	/*!
	 * \brief Constant begin iterator
	 * \return A constant iterator to the first element of the vector.
	 */
	template <class T>
	typename Vector<T>::iterator Vector<T>::cbegin() const{
		return this->m_first;
	}

	/*!
	 * \brief Constant end iterator
	 * \return A constant iterator to the last element of the vector.
	 */
	template <class T>
	typename Vector<T>::iterator Vector<T>::cend() const{
		return this->m_last;
	}
	/*}}}*/

	/* Iterator Implementation {{{*/

	template <class T>
	Vector<T>::iterator::iterator( T *ptr ){
		this->m_ptr = ptr;
	}

	template <class T>
	Vector<T>::iterator::~iterator() = default;

	template <class T>
	Vector<T>::iterator::iterator( const iterator &itr ){
		this->m_ptr( itr.m_ptr );
	}
	
	/*}}}*/
}
