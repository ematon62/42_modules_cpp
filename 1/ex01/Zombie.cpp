/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:51:11 by ematon            #+#    #+#             */
/*   Updated: 2025/04/09 16:57:26 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : name("undefined")
{
	std::cout << "New unnamed Zombie instance created" << std::endl;
}

Zombie::Zombie(std::string input) : name(input)
{
	std::cout << "New Zombie instance created with name " << input << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie instance named " << name << " destroyed\n";
}

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string input)
{
	this->name = input;
}