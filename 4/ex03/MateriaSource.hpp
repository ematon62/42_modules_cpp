/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:19:17 by ematon            #+#    #+#             */
/*   Updated: 2025/06/10 20:51:27 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include <cstdlib>
#include <cstdio>

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* _known_materias[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		MateriaSource& operator=(const MateriaSource& other);
		virtual ~MateriaSource();
		virtual void learnMateria(AMateria* m);
		virtual AMateria* createMateria(std::string const & type);
};

#endif