/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:31:38 by ematon            #+#    #+#             */
/*   Updated: 2025/06/17 10:35:19 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string& name, int sign_grade, int exec_grade)
: _name(name), _signed(false),
	_sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (_sign_grade < 1 || _exec_grade < 1)
		throw GradeTooHighException();
	if (_sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
: _name(other.getName()), _signed(other.getSigned()),
	_sign_grade(other.getSignGrade()),
	_exec_grade(other.getExecGrade())
{}

AForm::~AForm() {}

const std::string& AForm::getName() const
{
	return (_name);
}

bool AForm::getSigned() const
{
	return (_signed);
}

int AForm::getSignGrade() const
{
	return (_sign_grade);
}

int AForm::getExecGrade() const
{
	return (_exec_grade);
}

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _sign_grade)
		throw GradeTooLowException();
	_signed = true;
}

void AForm::verify(Bureaucrat const & executor) const
{
	if (!getSigned())
		throw NotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw Bureaucrat::GradeTooLowException();
}

const char* AForm::NotSignedException::what() const throw()
{
	return ("Form is not signed");
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("AForm grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("AForm grade is too low");
}

std::ostream& operator<<(std::ostream& str, const AForm& f)
{
	str << "AForm named " << f.getName()
		<< ", is: " << (f.getSigned() ? "" : "not ") << "signed"
		<< ", sign grade: " << f.getSignGrade()
		<< ", exec grade: " << f.getExecGrade() << std::endl;
	return (str);
}
