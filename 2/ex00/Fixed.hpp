/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 08:33:03 by grossviche        #+#    #+#             */
/*   Updated: 2025/05/15 13:48:55 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed &a);
        Fixed& operator=(const Fixed &a);
        ~Fixed();

		int		getRawBits() const;
		void	setRawBits(int const raw);

    private:
        int              _value;
        static const int _nbBits = 8;
};

#endif