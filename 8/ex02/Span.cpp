/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:32:12 by gross             #+#    #+#             */
/*   Updated: 2025/07/04 16:25:40 by gross            ###   ########.fr       */
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

Span::Span(const Span& other) : _N(other._N)
{
	for (unsigned int  i = 0; i < other._v.size(); i ++)
		_v.push_back(other._v[i]);
}

Span& Span::operator=(const Span& other)
{
	if (this == &other)
		return (*this);
	_N = other._N;
	for (unsigned int i = 0; i < other._v.size(); i ++)
		_v.push_back(other._v[i]);
	return (*this);
}

Span::~Span() {}

unsigned int ft_abs(int x)
{
	return (x < 0 ? -x : x);
}

int Span::longestSpan() const
{
	size_t n = _v.size();
	int spans[n][n];

	if (n <= 1)
		throw NoSpanException();
	for (unsigned int i = 0; i < n; i++)
	{
		for (unsigned int j = 0; j < n; j++)
		{
			if (i == j)
				spans[i][j] = -1;
			else
				spans[i][j] = ft_abs(_v[i] - _v[j]);
		}
	}

	int max = spans[0][1];
	for (unsigned int i = 0; i < n; i++)
	{
		for (unsigned int j = 0; j < n; j++)
		{
			if (spans[i][j] > 0 && spans[i][j] > max)
				max = spans[i][j];
		}
	}
	return (max);
}

int Span::shortestSpan() const
{
	size_t n = _v.size();
	int spans[n][n];

	if (n <= 1)
		throw NoSpanException();
	for (unsigned int i = 0; i < n; i++)
	{
		for (unsigned int j = 0; j < n; j++)
		{
			if (i == j)
				spans[i][j] = -1;
			else
				spans[i][j] = ft_abs(_v[i] - _v[j]);
		}
	}

	int min = spans[0][1];
	for (unsigned int i = 0; i < n; i++)
	{
		for (unsigned int j = 0; j < n; j++)
		{
			if (spans[i][j] > 0 && spans[i][j] < min)
				min = spans[i][j];
		}
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