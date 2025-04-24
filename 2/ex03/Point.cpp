/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:48:44 by ematon            #+#    #+#             */
/*   Updated: 2025/04/24 16:18:56 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(Fixed(0)), _y(Fixed(0)) {}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)) {}

Point::Point(const Point &p) : _x(p._x), _y(p._y) {}

Point& Point::operator=(const Point &p)
{
	if (this == &p)
		return (*this);
	*this = p;
	return (*this);
}

Point::~Point() {}

const Fixed Point::GetX() const
{
	return (_x);
}
const Fixed Point::GetY() const
{
	return (_y);
}