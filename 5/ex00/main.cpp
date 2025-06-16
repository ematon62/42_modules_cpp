/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:16:49 by ematon            #+#    #+#             */
/*   Updated: 2025/06/16 16:06:58 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "\033[1;31mWorking Bureaucrat\033[0m\n";
	try
	{
		Bureaucrat working(1, "working");
		std::cout << working;
		working.decrementGrade();
		std::cout << working;
		working.incrementGrade();
		std::cout << working;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	std::cout << "\033[1;31mWorking Bureaucrat 2\033[0m\n";
	try
	{
		Bureaucrat working2(150, "working2");
		std::cout << working2;
		working2.incrementGrade();
		std::cout << working2;
		working2.decrementGrade();
		std::cout << working2;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	
	std::cout << "\033[1;31mToo high grade init\033[0m\n";
	try
	{
		std::cout << "Initializing Bureaucrat of grade 0\n";
		Bureaucrat too_high_init(0, "too_high_init");
		std::cout << too_high_init;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	
	std::cout << "\033[1;31mToo low grade init\033[0m\n";
	try
	{
		std::cout << "Initializing Bureaucrat of grade 151\n";
		Bureaucrat too_low_init(151, "too_low_init");
		std::cout << too_low_init;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	std::cout << "\033[1;31mDecrement fail\033[0m\n";
	try
	{
		Bureaucrat decrement(150, "decrement");
		std::cout << decrement;
		std::cout << "Trying decrement...\n";
		decrement.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	std::cout << "\033[1;31mIncrement fail\033[0m\n";
	try
	{
		Bureaucrat increment(1, "increment");
		std::cout << increment;
		std::cout << "Trying increment...\n";
		increment.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
}