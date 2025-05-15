/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:38:30 by ematon            #+#    #+#             */
/*   Updated: 2025/05/15 11:21:32 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
	std::cout << "Instance Weapon of type " << _type << " created\n";
}

const std::string& Weapon::getType() const
{
	return (_type);
}

void Weapon::setType(std::string new_type)
{
	_type = new_type;
}