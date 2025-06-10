/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:17:29 by ematon            #+#    #+#             */
/*   Updated: 2025/06/10 20:50:55 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	_type = "cure";	
}

Cure::Cure(const Cure& other)
{
	_type = other.getType();
}

Cure& Cure::operator=(const Cure& other)
{
	if (this == &other)
		return (*this);
	this->_type = other.getType();
	return (*this);
}

Cure::~Cure() {}

AMateria* Cure::clone() const
{
	return (new Cure);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " + target.getName() + "'s wounds *\n";
}