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
#include <iomanip>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
	private:
	
	public:
		MutantStack();
		~MutantStack();

		//Underlying container can either be vector, deque or list
		//By default, deque
		typedef typename std::stack<T>::container_type underlying_type;

		//We create template type based on underlying container's iterators
		typedef typename underlying_type::iterator iterator;
		typedef typename underlying_type::const_iterator const_iterator;
		
		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
};

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {return (this->c.begin());}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {return (this->c.begin());}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {return (this->c.end());}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {return (this->c.end());}

#endif