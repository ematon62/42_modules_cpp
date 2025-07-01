/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:37:45 by gross             #+#    #+#             */
/*   Updated: 2025/07/01 13:45:45 by gross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int a = 2;

template<typename T>
void change_value(T& x)
{
	a = *x * 2;
}

template<typename T>
void print(const T& x)
{
    std::cout << x << std::endl;
}

int main(void)
{
	{
		const std::string array[] = {"caca", "pipi"};
		iter(array, 2, print);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		std::string array[] = {"caca", "pipi"};
		iter(array, 2, print);
	}
	std::cout << std::endl;
	{
		int* array[1];
		array[0] = &a;
		iter(array, 1, change_value);
	}

	std::cout << a << std::endl;
}