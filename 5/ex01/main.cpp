/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:16:49 by ematon            #+#    #+#             */
/*   Updated: 2025/06/16 17:58:56 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "\033[1;32mWorking Form and getters\033[0m\n";
	try
	{
		Form caca("working", 10, 20);
		std::cout << caca;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	
	std::cout << "\n\033[1;32mToo high sign grade\033[0m\n";
	try
	{
		std::cout << "Creating Form of sign grade 0\n";
		Form test("not working", 0, 20);
		std::cout << test;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	std::cout << "\033[1;32mToo low sign grade\033[0m\n";
	try
	{
		std::cout << "Creating Form of sign grade 151\n";
		Form test("not working", 151, 20);
		std::cout << test;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	std::cout << "\033[1;32mToo high exec grade\033[0m\n";
	try
	{
		std::cout << "Creating Form of exec grade 0\n";
		Form test("not working", 1, 0);
		std::cout << test;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	std::cout << "\033[1;32mToo low exec grade\033[0m\n";
	try
	{
		std::cout << "Creating Form of exec grade 151\n";
		Form test("not working", 20, 151);
		std::cout << test;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	
	std::cout << "\n\033[1;32mSuccessful signForm\033[0m\n";
	try
	{
		Form caca("successful", 10, 20);
		std::cout << caca;
		Bureaucrat pipi(10, "high_enough_bureaucrat");
		std::cout << pipi;
		pipi.signForm(caca);
		std::cout << caca;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	
	std::cout << "\033[1;32mUnsuccessful signForm\033[0m\n";
	try
	{
		Form caca("unsuccessful", 10, 20);
		std::cout << caca;
		Bureaucrat pipi(11, "too_low_bureaucrat");
		std::cout << pipi;
		std::cout << "Trying SignForm...\n";
		pipi.signForm(caca);
		std::cout << caca;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	std::cout << "\n\033[1;32mSuccessful beSigned\033[0m\n";
	try
	{
		Form caca("successful", 10, 20);
		std::cout << caca;
		Bureaucrat pipi(10, "high_enough_bureaucrat");
		std::cout << pipi;
		caca.beSigned(pipi);
		std::cout << caca;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	
	std::cout << "\033[1;32mUnsuccessful beSigned\033[0m\n";
	try
	{
		Form caca("unsuccessful", 10, 20);
		std::cout << caca;
		Bureaucrat pipi(11, "too_low_bureaucrat");
		std::cout << pipi;
		std::cout << "Trying beSigned...\n";
		caca.beSigned(pipi);
		std::cout << caca;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	
}