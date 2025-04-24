/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 08:33:03 by grossviche        #+#    #+#             */
/*   Updated: 2025/04/23 11:44:20 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#pragma once

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