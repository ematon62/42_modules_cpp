/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:31:54 by ematon            #+#    #+#             */
/*   Updated: 2025/06/05 11:53:54 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called\n";
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called\n";
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap assignment operator called\n";
	if (this == &other)
		return (*this);
	this->_name = other._name;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called\n";
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "ScavTrap overloaded constructor called\n";
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 20;
}

void ScavTrap::attack(const std::string& target)
{
	if (_hit_points == 0)
		std::cout << "ScavTrap " << _name << " is too dead to attack\n";
	else if (_energy_points == 0)
		std::cout << "ScavTrap " << _name << " is too tired to attack "
			<< target << std::endl;
	else
	{
		_energy_points--;
		std::cout << "ScavTrap " << _name << " causes " << _attack_damage
			<< " damage to " << target << std::endl;
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in gatekeeper mode\n";
}