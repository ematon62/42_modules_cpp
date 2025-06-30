/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:30:08 by gross             #+#    #+#             */
/*   Updated: 2025/06/30 14:21:43 by gross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base* generate()
{
	int	generated_random;

	generated_random = static_cast<int>((static_cast<double>(std::rand()) / RAND_MAX) * 3);
	switch(generated_random)
	{
		case IS_A:
			return (new A);
		case IS_B:
			return (new B);
		case IS_C:
			return (new C);
		default:
			return (NULL);
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B *>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C *>(p))
		std::cout << "C\n";
	else
		std::cout << "Base\n";
}

void identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "A\n";
		return ;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		dynamic_cast<B&>(p);
		std::cout << "B\n";
		return ;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		dynamic_cast<C&>(p);
		std::cout << "C\n";
		return ;
	}
	catch(const std::exception& e)
	{
	}
	std::cout << "Base\n";
}