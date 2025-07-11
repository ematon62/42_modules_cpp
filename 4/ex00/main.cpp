/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:00:13 by ematon            #+#    #+#             */
/*   Updated: 2025/06/11 21:08:08 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << "\033[1;33mAnimal\033[0m\n";
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete i;
		delete j;
	}
	std::cout << "\033[1;31mWrongAnimal\033[0m\n";
	{
		const WrongAnimal* meta2 = new WrongAnimal();
		const Animal* j2 = new Dog();
		const WrongAnimal* i2 = new WrongCat();
		std::cout << j2->getType() << " " << std::endl;
		std::cout << i2->getType() << " " << std::endl;
		i2->makeSound();
		j2->makeSound();
		meta2->makeSound();
		delete meta2;
		delete i2;
		delete j2;
	}
}