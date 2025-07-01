/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:34:31 by gross             #+#    #+#             */
/*   Updated: 2025/07/01 10:28:10 by gross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template<typename T>
class Array
{
	private:
		T* _elements;
		size_t _nb_elements;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		const T& operator[](int i) const;
		T& operator[](int i);
		~Array();
		size_t size() const;

	class IndexOutOfRange : public std::exception
	{
		virtual const char* what() const throw();
	};
};

template<typename T>
Array<T>::Array() : _nb_elements(0) {
	_elements = new T[0];
}

template<typename T>
Array<T>::Array(unsigned int n) : _nb_elements(n) {
	_elements = new T[n]();
}

template<typename T>
Array<T>::Array(const Array& other) : _nb_elements(other.size()) {
	_elements = new T[other.size()];
	for (unsigned int i = 0; i < other.size(); i++)
		_elements[i] = other[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (this == &other)
		return (*this);
	_nb_elements = other.size();
	if (_elements)
		delete [] _elements;
	_elements = new T[other.size()];
	for (unsigned int i = 0; i < other.size(); i++)
		_elements[i] = other[i];
	return (*this);
}

template<typename T>
Array<T>::~Array()
{
	delete [] _elements;
}

template<typename T>
const T& Array<T>::operator[](int i) const
{
	if (i >= 0 && i < static_cast<int>(_nb_elements))
		return (_elements[i]);
	throw Array<T>::IndexOutOfRange();
}

template<typename T>
T& Array<T>::operator[](int i)
{
	if (i >= 0 && i < static_cast<int>(_nb_elements))
		return (_elements[i]);
	throw Array<T>::IndexOutOfRange();
}

template<typename T>
const char * Array<T>::IndexOutOfRange::what() const throw()
{
	return ("Index out of bounds");
}

template<typename T>
size_t Array<T>::size() const
{
	return (_nb_elements);
}

#endif