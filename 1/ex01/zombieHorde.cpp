/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 21:47:11 by ematon            #+#    #+#             */
/*   Updated: 2025/04/06 22:24:35 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *horde;

	if (N < 1)
	{
		std::cerr << "Must be at least 1 zombie to make a horde\n";
		return (NULL);
	}
	horde = new Zombie[N];
	if (!horde)
	{
		std::cerr << "new: Could not allocated memory\n";
		return (NULL);
	}
	for (int i = 0; i < N; i ++)
	{
		horde[i].set_name(name);
	}
	return (horde);
}
