/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:19:35 by ematon            #+#    #+#             */
/*   Updated: 2025/06/11 10:09:03 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_known_materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._known_materias[i])
		{
			_known_materias[i] = other._known_materias[i]->clone();
			if (!_known_materias[i])
			{
				perror("malloc");
				exit(1);
			}
		}
		else
			_known_materias[i] = NULL;	
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this == &other)
		return (*this);
	for (int i = 0; i < 4; i++)
	{
		if (this->_known_materias[i])
		{
			delete this->_known_materias[i];
			this->_known_materias[i] = NULL;
		}
		if (other._known_materias[i])
		{
			this->_known_materias[i] = other._known_materias[i]->clone();
			if (!this->_known_materias[i])
			{
				perror("malloc");
				exit(1);
			}
		}
		else
			this->_known_materias[i] = NULL;
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_known_materias[i])
			delete _known_materias[i];
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!_known_materias[i])
		{
			_known_materias[i] = m;
			break ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_known_materias[i] && _known_materias[i]->getType() == type)
			return (_known_materias[i]->clone());
	}
	return (0);
}