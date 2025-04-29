/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grossviche <grossviche@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 18:00:13 by ematon            #+#    #+#             */
/*   Updated: 2025/04/29 10:55:54 by grossviche       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap binbin("binbin");
	ScavTrap jerem("jerem");
	jerem.attack("jean pierre");
	std::cout << std::endl;
	binbin.attack("jean pierre");
	jerem.beRepaired(10);
	binbin.beRepaired(100);
	jerem.guardGate();
	std::cout << binbin.getEP() << std::endl;
	std::cout << jerem.getEP() << std::endl;
}