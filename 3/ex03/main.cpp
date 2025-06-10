/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:00:13 by ematon            #+#    #+#             */
/*   Updated: 2025/06/05 12:29:20 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << "\n1\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::endl;
	DiamondTrap bb("bb");
	bb.whoAmI();
	std::cout << bb.getHP() << std::endl;
	std::cout << bb.getEP() << std::endl;
	std::cout << bb.getATKDmg() << std::endl;

	std::cout << "\n2\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::endl;
	DiamondTrap jp;
	jp.whoAmI();
	std::cout << jp.getHP() << std::endl;
	std::cout << jp.getEP() << std::endl;
	std::cout << jp.getATKDmg() << std::endl;

	std::cout << "\n3\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::endl;
	jp = DiamondTrap("je t'aime");
	jp.whoAmI();
	std::cout << jp.getHP() << std::endl;
	std::cout << jp.getEP() << std::endl;
	std::cout << jp.getATKDmg() << std::endl;
	jp.takeDamage(2);

	std::cout << "\n4\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::endl;
	DiamondTrap maman(jp);
	maman.whoAmI();
	std::cout << maman.getHP() << std::endl;
	std::cout << maman.getEP() << std::endl;
	std::cout << maman.getATKDmg() << std::endl;
}