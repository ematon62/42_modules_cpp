/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:48:41 by ematon            #+#    #+#             */
/*   Updated: 2025/05/15 14:07:57 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void )
{
	Point a;
	Point b(1, 2);
	Point c(2, 0);

	Point d(-100, -100);
	Point e(0.5f, 0.5f);
	Point f(0.2f, 0.4f);
	Point g(0.25f, 0.4f);
	std::cout << bsp(a, b, c, d) << std::endl;
	std::cout << bsp(a, b, c, e) << std::endl;
	std::cout << bsp(a, b, c, a) << std::endl;
	std::cout << bsp(a, b, c, b) << std::endl;
	std::cout << bsp(a, b, c, c) << std::endl;
	std::cout << bsp(a, b, c, f) << std::endl;
	std::cout << bsp(a, b, c, g) << std::endl;
}