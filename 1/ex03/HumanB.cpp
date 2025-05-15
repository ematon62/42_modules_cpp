/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:22:58 by ematon            #+#    #+#             */
/*   Updated: 2025/05/15 11:19:44 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _weapon(NULL), _name(name)
{
	std::cout << "HumanB instance created of name "
			<< _name << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB instance named " << this->_name << " destroyed\n";
}

void HumanB::attack() const
{
	if (!_weapon)
		std::cout << _name << " is unarmed and cannot attack\n";
	else
		std::cout << _name << " attacks with their weapon "
				<< _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &waerop)
{
	this->_weapon = &waerop;
}