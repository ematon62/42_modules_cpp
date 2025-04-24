/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 08:48:40 by grossviche        #+#    #+#             */
/*   Updated: 2025/04/24 09:31:03 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &a)
{
	std::cout << "Copy constructor called\n";
	this->_value = a.getRawBits();
}

Fixed& Fixed::operator=(const Fixed &a)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &a)
		return (*this);
	this->_value = a.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called\n";
	return (this->_value);
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called\n";
	this->_value = raw;
}