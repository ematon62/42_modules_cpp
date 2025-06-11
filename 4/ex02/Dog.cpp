/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grossviche <grossviche@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:22:15 by grossviche        #+#    #+#             */
/*   Updated: 2025/04/30 14:37:47 by grossviche       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog& other) : AAnimal(other)
{
	type = other.type;
	brain = new Brain();
	if (brain)
	{
		for (int i = 0; i < 100; i++)
			brain->changeNthIdea(other.brain->getNthIdea(i), i);
	}
}

Dog& Dog::operator=(const Dog& other)
{
	if (this == &other)
		return (*this);
	this->type = other.type;
	if (this->brain)
		delete brain;
	this->brain = new Brain();
	if (this->brain)
	{
		for (int i = 0; i < 100; i++)
			this->brain->changeNthIdea(other.brain->getNthIdea(i), i);
	}
	return (*this);
}

Dog::~Dog()
{
	if (brain)
		delete brain;
	std::cout << "Dog destructor called\n";
}

void Dog::makeSound() const
{
	std::cout << "\033[1;32mWouf\033[0m\n";
}

std::string Dog::getType() const
{
	return (type);
}

Brain* Dog::getBrainAddress() const
{
	return (brain);
}