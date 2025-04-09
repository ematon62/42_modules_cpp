/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:22:58 by ematon            #+#    #+#             */
/*   Updated: 2025/04/09 18:28:16 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _weapon(NULL), _name(name)
{
	std::cout << "HumanB instance created of name "
			<< this->_name << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB instance named " << this->_name << " destroyed\n";
}

void HumanB::attack() const
{
	if (!this->_weapon)
		std::cout << this->_name << " is unarmed and cannot attack\n";
	else
		std::cout << this->_name << " attacks with their weapon "
				<< this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &waerop)
{
	this->_weapon = &waerop;
}