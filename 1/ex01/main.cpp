/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 21:37:00 by ematon            #+#    #+#             */
/*   Updated: 2025/04/23 10:19:05 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *horde;
	int N = 100;
	std::string name = "jeremy";

	horde = zombieHorde(N, name);
	if (!horde)
		return (1);
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete []horde;
	return (0);
}
