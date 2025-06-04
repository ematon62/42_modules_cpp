/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:22:15 by grossviche        #+#    #+#             */
/*   Updated: 2025/06/04 15:59:05 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("animal")
{
}

Animal::Animal(const Animal& other) : type(other.type)
{
}

Animal& Animal::operator=(const Animal& other)
{
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