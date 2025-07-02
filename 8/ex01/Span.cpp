/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:32:12 by gross             #+#    #+#             */
/*   Updated: 2025/07/02 18:55:15 by gross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _N(N)
{
}

void Span::addNumber(int n)
{
	if (_v.size() == _N)
		throw SpanFullException();
	_v.push_back(n);
}

int Span::longestSpan() const
{
	if (_v.size() <= 1)
		throw NoSpanException();
	for (std::vector<int>::iterator it = _v.begin(); it != _v.end(); it++)
	{
		
	}
}

int Span::shortestSpan() const
{
	if (_v.size() <= 1)
		throw NoSpanException();
}

const char* Span::SpanFullException::what() const throw()
{
	return "Span instance is full";
}

const char* Span::NoSpanException::what() const throw()
{
	return "Insufficient number of elements in Span instance";
}