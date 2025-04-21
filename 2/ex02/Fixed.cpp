#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_value = 0;
}

Fixed::Fixed(const Fixed &a)
{
	*this = a;
}

Fixed::Fixed(const int v)
{
	this->setRawBits(v << this->_nbBits);
}

Fixed::Fixed(const float v)
{
	this->_value = roundf(v * (1 << this->_nbBits));
}

Fixed::~Fixed()
{
        //do nothing
}

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

Fixed& Fixed::operator=(const Fixed &a)
{
	if (this != &a)
		this->_value = a.getRawBits();
	return (*this);
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

static Fixed& min(Fixed &a, Fixed &b)
{
	return (a <= b ? a : b);
}

static Fixed& min(const Fixed &a, const Fixed &b)
{
	return (a <= b ? a : b);
}

static Fixed& max(Fixed &a, Fixed &b)
{
	return (a >= b ? a : b);
}

static Fixed& max(const Fixed &a, const Fixed &b)
{
	return (a >= b ? a : b);
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
