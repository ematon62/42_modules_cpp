/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 23:00:10 by gross             #+#    #+#             */
/*   Updated: 2025/07/02 18:09:23 by gross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	std::cout << "Containers are built on this array: {";

	int size = 4;
	int array[size];
	for (int i = 0; i < size; i++)
	{
		array[i] = i;
		std::cout << i << ((i < size - 1) ? ", " : "}\n");
	}

	std::cout << " * Vectors * \n";
	{
		std::vector<int> v(array, array + 4);
		for (int j = -5; j < 10; j++)
			std::cout << j << " is" << (easyfind(v, j) ? "" : " not")
				<< " in container\n";
	}

	std::cout << "\n * Deque * \n";
	{
		std::deque<int> v(array, array + 4);
		for (int j = -5; j < 10; j++)
			std::cout << j << " is" << (easyfind(v, j) ? "" : " not")
				<< " in container\n";
	}

	std::cout << "\n * List * \n";
	{
		std::list<int> v(array, array + 4);
		for (int j = -5; j < 10; j++)
			std::cout << j << " is" << (easyfind(v, j) ? "" : " not")
				<< " in container\n";
	}
}