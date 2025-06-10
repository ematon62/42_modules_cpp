/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:18:59 by ematon            #+#    #+#             */
/*   Updated: 2025/06/10 20:48:24 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <cstdlib>
#include <cstdio>

class Character : public ICharacter
{
	private:
		AMateria* _inventory[4];
		std::string _name;
	public:
		Character();
		Character(const std::string& name);
		Character(const Character& other);
		Character& operator=(const Character& other);
		virtual ~Character();
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
		AMateria* getItem(int idx);
};

#endif