/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:31:54 by ematon            #+#    #+#             */
/*   Updated: 2025/06/29 18:28:20 by gross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data()
{
	std::cout << "Data default constructor called\n";
	_name = "unknown";
}

Data::Data(const Data& other)
{
	std::cout << "Data copy constructor called\n";
	_name = other._name;
}

Data& Data::operator=(const Data& other)
{
	std::cout << "Data assignment operator called\n";
	if (this == &other)
		return (*this);
	this->_name = other._name;
	return (*this);
}

Data::~Data()
{
	std::cout << "Data destructor called\n";
}

Data::Data(const std::string& name)
{
	std::cout << "Data overloaded constructor called\n";
	_name = name;
}

std::string Data::getName() const
{
	return (_name);
}
