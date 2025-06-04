/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:00:13 by ematon            #+#    #+#             */
/*   Updated: 2025/06/04 16:27:10 by ematon           ###   ########.fr       */
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
	std::cout << "Allocation memory for array...";
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
	std::cout << "\nDestroying array elements...\n\n";
	for (int j = 0; j < ARRAY_SIZE; j++)
	{
		delete array[j];
	}

	std::cout << "\nChecking for shallow copy:\n";
	Dog jp;
	{
		Dog as = jp;
		std::cout << as.getBrainAddress()->getNthIdea(0) << std::endl;
		std::cout << &as.getBrainAddress()->getNthIdea(0) << std::endl;
	}
	std::cout << jp.getBrainAddress()->getNthIdea(0) << std::endl;
	std::cout << &jp.getBrainAddress()->getNthIdea(0) << std::endl;
}