/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:51:11 by ematon            #+#    #+#             */
/*   Updated: 2025/04/23 09:50:08 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string input)
{
	std::cout << "Zombie instance named " << input << " created\n";
	name = input;
}

Zombie::~Zombie()
{
	std::cout << "Zombie instance named " << name << " destroyed\n";
}

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}