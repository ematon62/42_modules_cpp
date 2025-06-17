/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:47:25 by ematon            #+#    #+#             */
/*   Updated: 2025/06/17 14:29:40 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("robotomy request form", 72, 45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	AForm::verify(executor);
	robotomy();
}

void RobotomyRequestForm::printTarget() const
{
	std::cout << getName()
		<< "'s target is " << _target << std::endl;
}

void RobotomyRequestForm::robotomy() const
{
	double	generated;
	
	std::srand(static_cast<unsigned int>(time(0)));
	std::cout << "JE SUIS UNE MACHINE QUI FAIT PLEIN DE BRUIT!!!!!!!!!!\n";
	generated = (static_cast<double>(std::rand()) / RAND_MAX);
	std::cout << _target + (generated <= 0.5f ? ROBOT_FAIL : ROBOT_SUCCESS)
		<< std::endl;
}