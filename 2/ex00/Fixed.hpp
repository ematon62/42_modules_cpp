/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grossviche <grossviche@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 08:33:03 by grossviche        #+#    #+#             */
/*   Updated: 2025/04/17 09:36:11 by grossviche       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
    private:
        int              _value;
        static const int _nbBits = 8;
    public:
        Fixed();
        Fixed(const Fixed &a);
        Fixed& operator=(const Fixed &a);
        ~Fixed();

		int		getRawBits() const;
		void	setRawBits(int const raw);
};