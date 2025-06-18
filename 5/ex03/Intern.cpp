/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:02:53 by ematon            #+#    #+#             */
/*   Updated: 2025/06/18 12:38:03 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const std::string forms[] = {"shrubbery creation",\
	"robotomy request", "presidential pardon"};

Intern::Intern()
{
	_makers[0] = &Intern::makeShrubbery;
	_makers[1] = &Intern::makeRobotomy;
	_makers[2] = &Intern::makePardon;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& form_type, const std::string& target)
{
	
	for (int i = 0; i < 3; i ++)
	{
		if (form_type == forms[i])
		{
			std::cout << "Intern creates " + form_type + " form.\n";
			return (this->*_makers[i])(target);
		}
	}
	std::cerr << "Intern couldn't create form\n";
	throw UnknownFormException();
	return (NULL);
}

AForm* Intern::makeShrubbery(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeRobotomy(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makePardon(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

const char* Intern::UnknownFormException::what() const throw()
{
	return ("Unknown Form type");
}