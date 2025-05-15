/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:40:19 by ematon            #+#    #+#             */
/*   Updated: 2025/05/15 13:49:34 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

#define EPSILON 0.00390625f

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &a);
		Fixed(const int v);
		Fixed(const float v);
		Fixed& operator=(const Fixed &a);
		~Fixed();

		bool operator<(const Fixed &a);
		bool operator>(const Fixed &a);
		bool operator<=(const Fixed &a);
		bool operator>=(const Fixed &a);
		bool operator==(const Fixed &a);
		bool operator!=(const Fixed &a);
		Fixed operator+(const Fixed &a);
		Fixed operator-(const Fixed &a);
		Fixed operator*(const Fixed &a);
		Fixed operator/(const Fixed &a);
		Fixed operator++();
		Fixed operator++(int);
		Fixed operator--();
		Fixed operator--(int);
		static Fixed& min(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);
		int		toInt(void) const;
		float	toFloat(void) const;
		int		getRawBits() const;
		void	setRawBits(int const raw);

	private:
		int              _value;
		static const int _nbBits = 8;

};

std::ostream	&operator<<(std::ostream &str, const Fixed &a);

#endif