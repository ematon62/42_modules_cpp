/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:40:56 by ematon            #+#    #+#             */
/*   Updated: 2025/04/24 09:36:43 by ematon           ###   ########.fr       */
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
	this->setRawBits(a.getRawBits());
}

Fixed& Fixed::operator=(const Fixed &a)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &a)
		return (*this);
	this->setRawBits(a.getRawBits());
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const int v) : _value(v << this->_nbBits)
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float v) : _value(roundf(v * (1 << this->_nbBits)))
{
	std::cout << "Float constructor called\n";
}

int	Fixed::getRawBits() const
{
	return (this->_value);
}

void Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}

int Fixed::toInt() const
{
	return (this->getRawBits() >> this->_nbBits);
}

float Fixed::toFloat() const
{
	return ((float)this->getRawBits() / (float)(1 << this->_nbBits));
}

std::ostream &operator<<(std::ostream &str, const Fixed &a)
{
	str << a.toFloat();
	return (str);
}
