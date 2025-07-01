/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:37:45 by gross             #+#    #+#             */
/*   Updated: 2025/06/30 21:30:16 by gross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	{
		const std::string array[] = {"caca", "pipi"};
		iter(array, 2, &print);
		std::cout << std::endl;
		iter(array, 2, &print2);

	}
	std::cout << std::endl;
	{
		int int_array[1] = { 1 };
		iter(int_array, 4, &increment);
		iter(int_array, 1, &print);
		iter(int_array, 1, &print);

	}
}