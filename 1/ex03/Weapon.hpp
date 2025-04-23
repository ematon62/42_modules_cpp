/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:38:26 by ematon            #+#    #+#             */
/*   Updated: 2025/04/23 11:38:15 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#pragma once

class Weapon
{
	public:
		Weapon(std::string type);
		const std::string& getType() const;
		void setType(std::string new_type);
	private:
		std::string _type;
};
