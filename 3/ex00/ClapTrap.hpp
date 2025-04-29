/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grossviche <grossviche@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:19:16 by ematon            #+#    #+#             */
/*   Updated: 2025/04/29 10:48:54 by grossviche       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#pragma once

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();
		
		ClapTrap(const std::string& name);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getName();
		int getHP();
		int getEP();
		int getATKDmg();

	private:
		std::string _name;
		int			_hit_points;
		int			_energy_points;
		int			_attack_damage;
		
};