/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:00:13 by ematon            #+#    #+#             */
/*   Updated: 2025/06/11 21:29:53 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define ARRAY_SIZE 100

int main(void)
{
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	delete i;
	delete j;
	
	std::cout << "Allocation memory for array...";
	AAnimal* array[ARRAY_SIZE];
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