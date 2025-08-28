/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:32:12 by gross             #+#    #+#             */
/*   Updated: 2025/07/05 10:25:49 by gross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N) : _N(N) {}


Span::Span(const Span& other) : _N(other._N), _v(other._v) {}

Span& Span::operator=(const Span& other)
{
	if (this == &other)
	return (*this);
	_N = other._N;
	_v = other._v;
	return (*this);
}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (_v.size() == _N)
		throw SpanFullException();
	_v.push_back(n);
}

void Span::addNumbers(std::vector<int>::iterator it,
	std::vector<int>::iterator jt)
{
	if (std::distance(it, jt) + _v.size() > _N)
		throw SpanFullException();
	_v.insert(_v.end(), it, jt);
}

int Span::longestSpan() const
{
	if (_v.size() <= 1)
		throw NoSpanException();

	std::vector<int> tmp = _v;
	std::sort(tmp.begin(), tmp.end());
	return (abs(tmp[0] - tmp[tmp.size() - 1]));
}

int Span::shortestSpan() const
{
	if (_v.size() <= 1)
	throw NoSpanException();
	
	std::vector<int> tmp = _v;
	std::sort(tmp.begin(), tmp.end());
	int min = abs(tmp[0] - tmp[1]);
	for (unsigned int i = 0; i < tmp.size() - 1; i++)
	{
		if (abs(tmp[i] - tmp[i + 1]) < min)
			min = abs(tmp[i] - tmp[i + 1]);
	}
	return (min);
}

const char* Span::SpanFullException::what() const throw()
{
	return "Span instance is full";
}

const char* Span::NoSpanException::what() const throw()
{
	return "Insufficient number of elements in Span instance";
}