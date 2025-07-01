/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:37:45 by gross             #+#    #+#             */
/*   Updated: 2025/07/01 10:42:24 by gross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	std::cout << "\033[1;31mTests: std::string\033[0m\n";

	std::cout << "\033[1;31mConstructeur par défaut\033[0m\n";
	{
		Array<std::string> a;
		try
		{
			std::cout << "a[0]: " << a[0] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << "a.size(): " << a.size() << std::endl;

		try
		{
			std::cout << "a[1]: " << a[1] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		try
		{
			std::cout << "a[-1]: " << a[-1] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

	}

	std::cout << "\033[1;31mConstructeur avec entier non signé\033[0m\n";
	{
		const Array<std::string> a(10);
		for (int i = -1; i < 11; i++)
		{
			try
			{
				std::cout << "a[" << i << "]: " << a[i] << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
		std::cout << "a.size(): " << a.size() << std::endl;
	}

	std::cout << "\033[1;31mConstructeur de copie\033[0m\n";
	{
		const Array<std::string> a(10);
		Array<std::string> b(a);

		std::cout << "On change les valeurs de b...\n";
		for (int i = -1; i < 11; i++)
		{
			try
			{
				b[i] = "modifié";
				std::cout << "b[" << i << "]: " << b[i] << std::endl;
				std::cout << "a[" << i << "]: " << a[i] << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
		std::cout << "a.size(): " << a.size() << std::endl;
		std::cout << "b.size(): " << b.size() << std::endl;
	}

	std::cout << "\033[1;31mOpérateur d'assignation\033[0m\n";
	{
		Array<std::string> a(10);
		Array<std::string> b;

		b = a;

		std::cout << "On change les valeurs de a...\n";
		for (int i = -1; i < 11; i++)
		{
			try
			{
				a[i] = "modifié";
				std::cout << "b[" << i << "]: " << b[i] << std::endl;
				std::cout << "a[" << i << "]: " << a[i] << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
		std::cout << "a.size(): " << a.size() << std::endl;
		std::cout << "b.size(): " << b.size() << std::endl;
	}

	std::cout << "\033[1;31mCopie profonde\033[0m\n";
	{
		Array<int> a(1);
		{
			const Array<int> b = a;
		}
		a[0] = 1;
		std::cout << "a[0]: " << a[0] << std::endl;
	}
}