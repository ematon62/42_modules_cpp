/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:12:29 by gross             #+#    #+#             */
/*   Updated: 2025/07/05 11:30:53 by gross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>
#include <exception>

template<typename T>
class MutantStack : public std::deque<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack& operator=(const MutantStack& other);
		~MutantStack();
		
		const T& top() const;
		T& top();
		void push(T elem);
		void pop();
};

template<typename T>
MutantStack<T>::MutantStack() {}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& other) { (void)other; }

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other) { (void)other; }

template<typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
T& MutantStack<T>::top() { return (this->back()); }

template <typename T>
const T& MutantStack<T>::top() const { return (this->back()); }

template <typename T>
void MutantStack<T>::push(T elem)  { return (this->push_back(elem)); }

template <typename T>
void MutantStack<T>::pop() { return (this->pop_back()); }

#endif