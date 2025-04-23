/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:23:00 by ematon            #+#    #+#             */
/*   Updated: 2025/04/23 11:38:27 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#pragma once

class HumanB
{
	public:
		HumanB(std::string name);
		~HumanB();
		void attack() const;
		void setWeapon(Weapon &waeorp);
	private:
		Weapon*		_weapon;
		std::string _name;
};