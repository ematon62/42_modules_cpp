/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:30:45 by ematon            #+#    #+#             */
/*   Updated: 2025/05/27 17:04:22 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
: ClapTrap("unknown_clap_name"), ScavTrap(), FragTrap(), _name("unknown")
{
	std::cout << "DiamondTrap default constructor called\n";
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 30;
}

DiamondTrap::DiamondTrap(const std::string& name)
: ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	std::cout << "DiamondTrap overloaded constructor called\n";
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
: ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name)
{
	std::cout << "DiamondTrap copy constructor called\n";
	ClapTrap::_name = other._name + "_clap_name";
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 30;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap assignment operator called\n";
	if (this == &other)
		return (*this);
	ClapTrap::_name = other._name + "_clap_name";
	_name = other._name;
	_hit_points = 100;
	_energy_points = 50;
	_attack_damage = 30;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called\n";
}

void DiamondTrap::whoAmI()
{
	std::cout << ClapTrap::_name << std::endl;
	std::cout << _name << std::endl;
}
