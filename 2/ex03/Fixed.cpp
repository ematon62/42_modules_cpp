/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:40:27 by ematon            #+#    #+#             */
/*   Updated: 2025/04/24 09:52:44 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const Fixed &a) : _value(a.getRawBits()) {}

Fixed::Fixed(const int v) : _value(v << this->_nbBits) {}

Fixed::Fixed(const float v) : _value(roundf(v * (1 << this->_nbBits))) {}

Fixed& Fixed::operator=(const Fixed &a)
{
	if (this == &a)
		return (*this);
	this->setRawBits(a.getRawBits());
	return (*this);
}

Fixed::~Fixed() {}

bool Fixed::operator>(const Fixed &a)
{
	return (a.toFloat() > this->toFloat());
}

bool Fixed::operator<(const Fixed &a)
{
	return (a.toFloat() < this->toFloat());
}

bool Fixed::operator>=(const Fixed &a)
{
	return (a.toFloat() >= this->toFloat());
}

bool Fixed::operator<=(const Fixed &a)
{
	return (a.toFloat() <= this->toFloat());
}

bool Fixed::operator==(const Fixed &a)
{
	return (a.toFloat() == this->toFloat());
}

bool Fixed::operator!=(const Fixed &a)
{
	return (a.toFloat() != this->toFloat());
}

Fixed Fixed::operator+(const Fixed &a)
{
	Fixed b(a.toFloat() + this->toFloat());
	return b;
}

Fixed Fixed::operator-(const Fixed &a)
{
	Fixed b(a.toFloat() - this->toFloat());
	return b;
}

Fixed Fixed::operator*(const Fixed &a)
{
	Fixed b(a.toFloat() * this->toFloat());
	return b;
}

Fixed Fixed::operator/(const Fixed &a)
{
	Fixed b(a.toFloat() / this->toFloat());
	return b;
}

Fixed Fixed::operator++()
{
	*(this) = *(this) + Fixed(EPSILON);
	return *(this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++(*this);
	return temp;
}

Fixed Fixed::operator--()
{
	*(this) = *(this) - Fixed(EPSILON);
	return *(this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--(*this);
	return temp;
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return (a <= b ? a : b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a.toFloat() <= b.toFloat() ? a : b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return (a >= b ? a : b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a.toFloat() >= b.toFloat() ? a : b);
}

int Fixed::toInt() const
{
        return (this->getRawBits() >> this->_nbBits);
}

float Fixed::toFloat() const
{
        return ((float)this->getRawBits() / (1 << this->_nbBits));
}

int	Fixed::getRawBits() const
{
	return (this->_value);
}

void Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}

std::ostream &operator<<(std::ostream &str, const Fixed &a)
{
	str << a.toFloat();
	return (str);
}
