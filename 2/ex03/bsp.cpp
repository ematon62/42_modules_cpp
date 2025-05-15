/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 09:54:30 by ematon            #+#    #+#             */
/*   Updated: 2025/05/15 14:03:56 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed x(point.GetX());
	Fixed y(point.GetY());
	Fixed xa(a.GetX());
	Fixed ya(a.GetY());
	Fixed xb(b.GetX());
	Fixed yb(b.GetY());
	Fixed xc(c.GetX());
	Fixed yc(c.GetY());

	Fixed t;
	Fixed p;

	t = ((x - xa) * (yc - ya) - (y - ya) * (xc - xa))
		/ ((xb - xa) * (yc - ya) - (yb - ya) * (xc - xa));
	p = ((xb - xa) * (y - ya) - (yb - ya) * (x - xa))
		/ ((xb - xa) * (yc - ya) - (yb - ya) * (xc - xa));
	
	return (t > Fixed(0) && p > Fixed(0) && (p + t < Fixed(1)));
}