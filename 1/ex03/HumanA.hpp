/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:22:55 by ematon            #+#    #+#             */
/*   Updated: 2025/05/15 11:15:58 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A
#define HUMAN_A

#include "Weapon.hpp"

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

#endif