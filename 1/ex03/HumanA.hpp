/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:22:55 by ematon            #+#    #+#             */
/*   Updated: 2025/04/23 11:38:00 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#pragma once

class HumanA
{
	public:
		HumanA(std::string name, Weapon &weaponi);
		~HumanA();
		void attack() const;
	private:
		Weapon		&_weapon;
		std::string _name;
};
