/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:54:54 by ematon            #+#    #+#             */
/*   Updated: 2025/06/10 20:50:16 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("default")
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const std::string& name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character& other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
		{
			_inventory[i] = other._inventory[i]->clone();
			if (!_inventory[i])
			{
				perror("malloc");
				exit(1);
			}
		}
		else
			_inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character& other)
{
	if (this == &other)
		return (*this);
	this->_name = other._name;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (other._inventory[i])
		{
			this->_inventory[i] = other._inventory[i]->clone();
			if (!this->_inventory[i])
			{
				perror("malloc");
				exit(1);
			}
		}
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

std::string const & Character::getName() const
{
	return (_name);	
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			break ;
		}
	}
}


void Character::unequip(int idx)
{
	if ((0 <= idx) && (idx <= 3))
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (((0 <= idx) && (idx <= 3)) && _inventory[idx])
	_inventory[idx]->use(target);
}

AMateria* Character::getItem(int idx)
{
	return (_inventory[idx]);
}