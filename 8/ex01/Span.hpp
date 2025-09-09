/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:12:29 by gross             #+#    #+#             */
/*   Updated: 2025/07/05 10:20:11 by gross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <cmath>

class Span
{
	private:
		unsigned int _N;
		std::vector<int> _v;
		Span();
	public:
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
		void addNumber(int n);
		void addNumbers(std::vector<int>::iterator it,
			std::vector<int>::iterator jt);
		int shortestSpan() const;
		int longestSpan() const;
		void printContents();
		
		class SpanFullException : public std::exception
		{
			const char* what() const throw();
		};

		class NoSpanException : public std::exception
		{
			const char* what() const throw();
		};
};

#endif