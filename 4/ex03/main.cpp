/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 20:43:30 by ematon            #+#    #+#             */
/*   Updated: 2025/06/11 10:34:03 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");

	std::cout << "\033[1;31mTest initial\033[0m\n";
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "\033[1;31mEquip\033[0m\n";
	me->equip(new Ice());
	me->equip(new Cure());
	AMateria* caca = new Ice();
	me->equip(caca);
	for (int i = 0; i < 4; i++)
		me->use(i, *bob);

	std::cout << "\033[1;31mUnequip\033[0m\n";
	AMateria* temp = me->getItem(0);
	me->unequip(0);
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "\033[1;31mMateria inconnue\033[0m\n";
	std::cout << "Valeur de retour: " << src->createMateria("caca") << std::endl;

	std::cout << "\033[1;31mDuplicité\033[0m\n";
	me->equip(temp);
	me->equip(temp);
	for (int i = 0; i < 4; i++)
		me->use(i, *me);

	delete bob;
	delete me;
	delete src;
	delete caca;
}