/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:39:59 by ematon            #+#    #+#             */
/*   Updated: 2025/05/15 13:49:09 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &a);
		Fixed(const int v);
		Fixed(const float v);
		Fixed& operator=(const Fixed &a);
		~Fixed();

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