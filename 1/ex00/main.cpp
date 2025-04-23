/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 21:37:00 by ematon            #+#    #+#             */
/*   Updated: 2025/04/23 09:54:34 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *new_guy;
	Zombie *new_dude;
	Zombie *new_man;
	
	new_guy = newZombie("guy");
	new_dude = newZombie("dude");
	new_dude->announce();
	new_man = newZombie("man");
	new_man->announce();
	delete new_man;
	if (!new_guy)
	{
		std::cerr << "new: Could not allocate memory\n";
		return (1);
	}
	randomChump("chump");
	new_guy->announce();
	delete new_guy;
	delete new_dude;
	return (0);
}
