/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:48:08 by ematon            #+#    #+#             */
/*   Updated: 2025/06/17 14:20:28 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("shrubbery creation form", 145, 137), _target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	AForm::verify(executor);
	shrubber();
}

void ShrubberyCreationForm::printTarget() const
{
	std::cout << getName()
		<< "'s target is " << _target << std::endl;
}

void ShrubberyCreationForm::shrubber() const
{
	std::ofstream shrubberyfile((_target + "_shrubbery").c_str());
	if (!shrubberyfile.good())
		throw BadFileException();
	shrubberyfile << TREE;
}

const char* ShrubberyCreationForm::BadFileException::what() const throw()
{
	return ("Couldn't open shrubbery file");
}