/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 21:37:00 by ematon            #+#    #+#             */
/*   Updated: 2025/04/06 22:16:39 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *new_guy;
	
	new_guy = newZombie("chumby");
	if (!new_guy)
	{
		std::cerr << "new: Could not allocate memory\n";
		return (1);
	}
	randomChump("chumbo");
	new_guy->announce();
	delete new_guy;
	return (0);
}
