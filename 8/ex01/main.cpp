/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 23:00:10 by gross             #+#    #+#             */
/*   Updated: 2025/07/05 10:32:15 by gross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#ifndef SIZE
#  define SIZE 1000000
#endif

int main()
{
	std::cout << " * Span size = 0 *\n";
	{
		Span sp(0);
		
		std::cout << "Adding number...\n";
		try
		{
			sp.addNumber(0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << "Getting longest and shortest spans...\n";
		try
		{
			sp.longestSpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			sp.shortestSpan();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
	std::cout << "\n * Mega fat Span of size " << SIZE << " *\n";;
	{
		Span sp(SIZE);
		
		std::cout << "Filling span\n";
		for (int i = -1; i < SIZE - 1; i++)
		{
				sp.addNumber(i);
		}
		std::cout << "Printing...\n";
		sp.printContents();
		
		std::cout << "Longest and shortest span: \n";
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		
		std ::cout << "Trying addNumber...\n";
		try
		{
			sp.addNumber(0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << "\n * addNumbers *\n";
	{
		Span sp(SIZE);
		std::vector<int> vec;
		
		std::cout << "Filling vector\n";
		for (int i = 0; i < SIZE; i++)
		{
			vec.push_back(i);
		}

		std::cout << "Trying addNumbers...\n";
		try
		{
			sp.addNumbers(vec.begin(), vec.end());
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		sp.printContents();

		std::cout << "Longest and shortest span: \n";
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		
		std ::cout << "Trying addNumber...\n";
		try
		{
			sp.addNumber(0);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << "\n * Main du sujet *\n";
	{
		Span sp = Span(7);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		std::cout << "Trying addNumbers...\n";
		std::vector<int> v2(5, 10);
		try
		{
			sp.addNumbers(v2.begin(), v2.end());
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		std::vector<int> v3(2, 10);
		try
		{
			sp.addNumbers(v3.begin(), v3.end());
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	return 0;
}