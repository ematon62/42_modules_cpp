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
	std::cout << "Cat default constructor called\n";
	type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy constructor called\n";
	type = other.type;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat overloaded assignment operator called\n";
	if (this == &other)
		return (*this);
	this->type = other.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
}

void Cat::makeSound() const
{
	std::cout << "Miaou\n";
}