/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:10:45 by ematon            #+#    #+#             */
/*   Updated: 2025/06/10 20:51:10 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	_type = "ice";	
}

Ice::Ice(const Ice& other)
{
	_type = other.getType();
}

Ice& Ice::operator=(const Ice& other)
{
	if (this == &other)
		return (*this);
	this->_type = other.getType();
	return (*this);
}

Ice::~Ice() {}

AMateria* Ice::clone() const
{
	return (new Ice);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " + target.getName() + " *\n";
}