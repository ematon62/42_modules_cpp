/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 17:44:23 by ematon            #+#    #+#             */
/*   Updated: 2025/04/23 11:37:23 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#pragma once

class Zombie
{
	public:
		Zombie(std::string name);
		~Zombie();
		void announce(void);

	private:
		std::string name;
};

Zombie* newZombie( std::string name );
void 	randomChump( std::string name );