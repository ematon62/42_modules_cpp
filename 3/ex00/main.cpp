/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:00:13 by ematon            #+#    #+#             */
/*   Updated: 2025/06/05 11:47:31 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap jerem("jeremy");
	std::cout << "jerem a " << jerem.getEP() << " points d'énergie\n";
	std::cout << "jerem a " << jerem.getHP() << " points de vie\n";
	std::cout << "jerem peut causer " << jerem.getATKDmg() << " points de degats\n";
	jerem.attack("jean pierre");
	jerem.takeDamage(1);
	std::cout << "jerem a " << jerem.getEP() << " points d'énergie\n";
	std::cout << "jerem a " << jerem.getHP() << " points de vie\n";
	jerem.beRepaired(1);
	std::cout << "jerem a " << jerem.getEP() << " points d'énergie\n";
	std::cout << "jerem a " << jerem.getHP() << " points de vie\n";
	jerem.takeDamage(-1000);
	std::cout << "jerem a " << jerem.getEP() << " points d'énergie\n";
	std::cout << "jerem a " << jerem.getHP() << " points de vie\n";
	jerem.takeDamage(1000);
	jerem.attack("Dieu");
	jerem.beRepaired(1);

	std::cout << std::endl;
	ClapTrap bb;
	for(int i = 0; i < 10; i++)
		bb.attack("cc");
	std::cout << "bb a " << bb.getEP() << " points d'énergie\n";
	std::cout << "bb a " << bb.getHP() << " points de vie\n";
	bb.attack("cc");
	bb.beRepaired(1000);
	bb.takeDamage(2);
}