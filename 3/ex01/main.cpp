/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:00:13 by ematon            #+#    #+#             */
/*   Updated: 2025/06/05 15:27:24 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "\033[1;31mClapTrap\033[0m\n";
	{
	ClapTrap binbin("binbin");
	binbin.attack("jean pierre");
	binbin.beRepaired(100);
	std::cout << "binbin a " << binbin.getEP() << " points d'énergie\n";
	std::cout << "binbin a " << binbin.getHP() << " points de vie\n";
	std::cout << "binbin peut causer " << binbin.getATKDmg() << " points de degats\n";
	}
	std::cout << std::endl;
	std::cout << "\033[1;31mScavTrap\033[0m\n";
	{
	ScavTrap bb;
	std::cout << "bb a " << bb.getEP() << " points d'énergie\n";
	std::cout << "bb a " << bb.getHP() << " points de vie\n";
	std::cout << "bb peut causer " << bb.getATKDmg() << " points de degats\n";
	bb.guardGate();
	bb.attack("jean pierre");
	bb.takeDamage(1);
	bb.beRepaired(1);
	bb.takeDamage(1000);
	bb.beRepaired(1);
	bb.guardGate();
	}
	std::cout << std::endl;
	std::cout << "\033[1;31mCopies de ScavTrap\033[0m\n";
	{
	ScavTrap jerem("jerem");
	jerem.takeDamage(20);
	std::cout << "jerem a " << jerem.getEP() << " points d'énergie\n";
	std::cout << "jerem a " << jerem.getHP() << " points de vie\n";
	std::cout << "jerem peut causer " << jerem.getATKDmg() << " points de degats\n";

	ScavTrap jerome(jerem);
	std::cout << "jerome a " << jerome.getEP() << " points d'énergie\n";
	std::cout << "jerome a " << jerome.getHP() << " points de vie\n";
	std::cout << "jerome peut causer " << jerome.getATKDmg() << " points de degats\n";
	jerome.beRepaired(1000);

	ScavTrap final = jerome;
	std::cout << "final a " << final.getEP() << " points d'énergie\n";
	std::cout << "final a " << final.getHP() << " points de vie\n";
	std::cout << "final peut causer " << final.getATKDmg() << " points de degats\n";
	}
}