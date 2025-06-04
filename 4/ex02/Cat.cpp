/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grossviche <grossviche@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:22:15 by grossviche        #+#    #+#             */
/*   Updated: 2025/04/30 14:37:47 by grossviche       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat& other) : AAnimal(other)
{
	type = other.type;
	brain = new Brain();
	if (brain)
	{
		for (int i = 0; i < 100; i++)
			brain->changeNthIdea(other.brain->getNthIdea(i), i);
	}
}

Cat& Cat::operator=(const Cat& other)
{
	if (this == &other)
		return (*this);
	this->type = other.type;
	brain = new Brain();
	if (brain)
	{
		for (int i = 0; i < 100; i++)
			brain->changeNthIdea(other.brain->getNthIdea(i), i);
	}
	return (*this);
}

Cat::~Cat()
{
	if (brain)
		delete brain;
	std::cout << "Cat destructor called\n";
}

void Cat::makeSound() const
{
	std::cout << "Miaou\n";
}

std::string Cat::getType() const
{
	return (type);
}

Brain* Cat::getBrainAddress() const
{
	return (brain);
}