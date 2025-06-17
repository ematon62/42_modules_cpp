/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:53:35 by ematon            #+#    #+#             */
/*   Updated: 2025/06/17 13:40:56 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm("presidential pardon form", 25, 5), _target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	AForm::verify(executor);
	pardon();
}

void PresidentialPardonForm::printTarget() const
{
	std::cout << getName()
		<< "'s target is " << _target << std::endl;
}

void PresidentialPardonForm::pardon() const
{
	std::cout << _target + " has been pardoned by Zaphod Beeblebrox.\n";
}