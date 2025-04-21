#include <iostream>
#include <cmath>

#define EPSILON 0.00390625f

class Fixed
{
	private:
	int              _value;
	static const int _nbBits = 8;

	public:
	Fixed();
	Fixed(const Fixed &a);
	Fixed(const int v);
	Fixed(const float v);
	~Fixed();

	bool operator<(const Fixed &a);
	bool operator>(const Fixed &a);
	bool operator<=(const Fixed &a);
	bool operator>=(const Fixed &a);
	bool operator==(const Fixed &a);
	bool operator!=(const Fixed &a);

	Fixed& operator=(const Fixed &a);
	Fixed operator+(const Fixed &a);
	Fixed operator-(const Fixed &a);
	Fixed operator*(const Fixed &a);
	Fixed operator/(const Fixed &a);

	Fixed operator++();
	Fixed operator++(int);
	Fixed operator--();
	Fixed operator--(int);

	static Fixed& min(Fixed &a, Fixed &b);
	static Fixed& min(const Fixed &a, const Fixed &b);
	static Fixed& max(Fixed &a, Fixed &b);
	static Fixed& max(const Fixed &a, const Fixed &b);

	int		toInt(void) const;
	float	toFloat(void) const;
		
	int		getRawBits() const;
	void	setRawBits(int const raw);
};

std::ostream	&operator<<(std::ostream &str, const Fixed &a);
