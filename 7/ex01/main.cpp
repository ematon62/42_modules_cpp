/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:37:45 by gross             #+#    #+#             */
/*   Updated: 2025/06/30 16:54:40 by gross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	{
		std::string array[] = {"caca", "pipi"};
		iter(array, 2, &print);
		std::cout << std::endl;
		iter(array, 2, &print2);
	}
	std::cout << std::endl;
	{
		int int_array[] = {1, 2, 3, 4};
		iter(int_array, 4, &set_value);
		iter(int_array, 4, print);
	}
}