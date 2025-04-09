/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:22:53 by ematon            #+#    #+#             */
/*   Updated: 2025/04/09 18:13:47 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weap) : _weapon(weap), _name(name) 
{
	std::cout << "HumanA instance created, named " << _name
			<< " armed with " << _weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA instance named " << this->_name << " destroyed\n";
}

void HumanA::attack() const
{
	std::cout << this->_name << " attacks with their weapon "
			<< this->_weapon.getType() << std::endl;
}
