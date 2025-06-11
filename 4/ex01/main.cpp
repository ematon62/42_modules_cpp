/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:00:13 by ematon            #+#    #+#             */
/*   Updated: 2025/06/11 21:24:38 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define ARRAY_SIZE 100

int main(void)
{
	std::cout << "\033[1;33mAllocation memory for array...\033[0m\n";
	Animal* array[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		if (i % 2)
			array[i] = new Cat();
		else
			array[i] = new Dog();
		if (!array[i])
			return (1);
	}
	std::cout << "\033[1;33mDestroying array elements...\033[0m\n";
	for (int j = 0; j < ARRAY_SIZE; j++)
	{
		delete array[j];
	}

	std::cout << "\033[1;33mSetting and getting ideas...\033[0m\n";
	Cat jp;
	jp.getBrainAddress()->changeNthIdea("caca", 0);
	std::cout << jp.getBrainAddress()->getNthIdea(0) << std::endl;
	std::cout << &jp.getBrainAddress()->getNthIdea(0) << std::endl;

	std::cout << "\033[1;33mChecking for shallow copy...\033[0m\n";
	{
		Cat as;
		as = jp;
		std::cout << as.getBrainAddress()->getNthIdea(0) << std::endl;
		std::cout << &as.getBrainAddress()->getNthIdea(0) << std::endl;
	}
}