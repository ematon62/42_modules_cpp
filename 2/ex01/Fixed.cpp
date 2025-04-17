#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &a)
{
	std::cout << "Copy constructor called\n";
	*this = a;
}

Fixed::Fixed(const int v)
{
	std::cout << "Int constructor called\n";
	this->_value = v << this->_nbBits;
}

Fixed::Fixed(const float v)
{
	std::cout << "Float constructor called\n";
	this->_value = (int)(v * (1 << this->_nbBits));
}

Fixed& Fixed::operator=(const Fixed &a)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &a)
		this->_value = a._value;
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

int Fixed::toInt() const
{
	return (this->_value >> this->_nbBits);
}

float Fixed::toFloat() const
{
	return ((float)this->_value / (float)(1 << this->_nbBits));
}

std::ostream &operator<<(std::ostream &str, const Fixed &a)
{
	str << a.toFloat();
	return (str);
}
