/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 09:54:30 by ematon            #+#    #+#             */
/*   Updated: 2025/04/24 16:54:44 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed t;
	Fixed p;

	Fixed u(point.GetX().toFloat() - a.GetX().toFloat());
	Fixed v(point.GetY().toFloat()- a.GetY().toFloat());
	Fixed w(b.GetX().toFloat() - a.GetX().toFloat());
	Fixed x(b.GetY().toFloat() - a.GetY().toFloat());
	Fixed y(c.GetX().toFloat() - a.GetX().toFloat());
	Fixed z(c.GetY().toFloat() - a.GetY().toFloat());

	
	float ft = t.toFloat();
	float fp = p.toFloat();
	std::cout << ft << std::endl;
	std::cout << fp << std::endl;

	return (fp >= 0 && ft >= 0 && (fp + ft <= 1));
}