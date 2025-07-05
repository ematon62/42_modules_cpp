/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:12:29 by gross             #+#    #+#             */
/*   Updated: 2025/07/04 16:05:53 by gross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>

class Span
{
	private:
		std::vector<int> _v;
		unsigned int _N;
		Span();
	public:
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
		void addNumber(int n);
		int shortestSpan() const;
		int longestSpan() const;
		
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