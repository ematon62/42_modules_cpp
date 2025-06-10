/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grossviche <grossviche@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:22:15 by grossviche        #+#    #+#             */
/*   Updated: 2025/04/30 14:37:47 by grossviche       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called\n";
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called\n";
	type = other.type;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat overloaded assignment operator called\n";
	if (this == &other)
		return (*this);
	this->type = other.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called\n";
}