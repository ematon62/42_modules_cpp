/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grossviche <grossviche@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:22:15 by grossviche        #+#    #+#             */
/*   Updated: 2025/04/30 14:48:44 by grossviche       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("animal")
{
	std::cout << "Animal default constructor called\n";
}

Animal::Animal(const Animal& other) : type(other.type)
{
	std::cout << "Animal copy constructor called\n";
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal overloaded assignment operator called\n";
	if (this == &other)
		return (*this);
	this->type = other.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called\n";
}

void Animal::makeSound() const
{
	std::cout << "animal sound\n";
}

std::string Animal::getType() const
{
	return (type);
}