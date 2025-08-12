/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:12:29 by gross             #+#    #+#             */
/*   Updated: 2025/07/04 16:05:53 by gross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MutantStack_HPP
#define MutantStack_HPP

#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <deque>
#include <exception>

// (constructor)
// (destructor)
// operator=
// top
// empty
// size
// push
// pop
//iterators
template <typename T>
class MutantStack : public std::deque<T>
{
	public:
		T& top();
		const T& top() const;
		void push(T elem);
		void pop();
};

template <typename T>
T& MutantStack<T>::top() 
{
	return (this->back());
}

template <typename T>
const T& MutantStack<T>::top() const
{
	return (this->back());
}

template <typename T>
void MutantStack<T>::push(T elem) 
{
	return (this->push_back(elem));
}

template <typename T>
void MutantStack<T>::pop() 
{
	return (this->pop_back());
}

#endif