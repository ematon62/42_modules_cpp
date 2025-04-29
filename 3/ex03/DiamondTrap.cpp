/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grossviche <grossviche@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:32:15 by grossviche        #+#    #+#             */
/*   Updated: 2025/04/29 17:39:02 by grossviche       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
: ClapTrap("unknown_clap_name")
{
	std::cout << "DiamondTrap default constructor called\n";
	this->_name = "unknown";
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
: ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	

	std::cout << "DiamondTrap copy constructor called\n";
	this->_name = "unknown";
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "ClapTrap assignment operator called\n";
	if (this == &other)
		return (*this);
	this->ClapTrap::_name = other.ClapTrap::_name;
	this->_name = other._name;
	this->_hit_points = other._hit_points;
	this->_energy_points = other._energy_points;
	this->_attack_damage = other._attack_damage;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called\n";
}

DiamondTrap::DiamondTrap(const std::string& name)
: ClapTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap overloaded constructor called\n";
	this->_name = name;
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
}

void DiamondTrap::attack(const std::string& name)
{
	ScavTrap::attack(name);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << _name << std::endl
		<< "Claptrap name: " << ClapTrap::_name << std::endl;
}
