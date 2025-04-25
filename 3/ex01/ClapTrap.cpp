/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:31:54 by ematon            #+#    #+#             */
/*   Updated: 2025/04/24 18:04:45 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
{
	std::cout << "ClaTrap constructor called\n";
	_name = name;
	_hit_points = 10;
	_energy_points = 10;
	_attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	_name = other._name;
	_hit_points = 10;
	_energy_points = 10;
	_attack_damage = 0;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this == &other)
		return (*this);
	this->_name = other._name;
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Claptrap destructor called\n";
}

void ClapTrap::attack(const std::string& target)
{
	if (_hit_points <= 0)
		std::cout << "ClapTrap " << _name << " is too dead to attack\n";
	else if (_energy_points <= 0)
		std::cout << "ClapTrap " << _name << " is too tired to attack "
			<< target << std::endl;
	else
	{
		_energy_points--;
		std::cout << "ClapTrap " << _name << " causes " << _attack_damage
			<< " to " << target << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_points < 0)
		std::cout << "ClapTrap " << _name << " is already dead\n";
	else if (_hit_points - amount <= 0)
	{
		_hit_points -= amount;
		std::cout << "ClapTrap " << _name << " takes " << amount
			<< " points of damage and is killed in the process\n";
	}
	else
	{
		_hit_points -= amount;
		std::cout << "Claptrap " << _name << " takes " << amount
			<< " points of damage\n";
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hit_points <= 0)
		std::cout << "ClapTrap " << _name << " is too dead to heal itself\n";
	else if (_energy_points <= 0)
		std::cout << "ClapTrap " << _name << " is too tired to heal itself\n";
	else
	{
		_energy_points--;
		_hit_points += amount;
		std::cout << "Claptrap " << _name << " heals itself for " << amount
			<< " hit points\n";
	}
}