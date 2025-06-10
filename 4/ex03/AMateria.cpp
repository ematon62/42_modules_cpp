/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 11:11:19 by ematon            #+#    #+#             */
/*   Updated: 2025/06/10 20:47:19 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("default")
{
}

AMateria::AMateria(std::string const & type) : _type(type)
{
}

AMateria::AMateria(const AMateria& other)
{
	_type = other.getType();
}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this == &other)
		return (*this);
	this->_type = other.getType();
	return (*this);
}

AMateria::~AMateria()
{	
}

std::string const &AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* uses " + _type + " on " + target.getName() + " *\n";
}