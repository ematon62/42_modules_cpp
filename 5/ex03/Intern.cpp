/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:02:53 by ematon            #+#    #+#             */
/*   Updated: 2025/06/17 16:01:22 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& form_type, const std::string& target) const
{
	int i = 0;
	// for (i; i < 3; i ++)
	// {
	// 	if (form_type == forms[i])
	// 	{
	// 		std::cout << "Intern creates " + form_type + "form.\n";
	// 		return ();
	// 	}
	}
	std::cerr << "Intern couldn't create form\n";
	throw UnknownFormException();
	return (NULL);
}

const char* Intern::UnknownFormException::what() const throw()
{
	return ("Unknown Form type");
}