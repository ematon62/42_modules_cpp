/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:31:38 by ematon            #+#    #+#             */
/*   Updated: 2025/06/16 16:50:27 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string& name, int sign_grade, int exec_grade)
: _name(name), _signed(false),
	_sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (_sign_grade < 1 || _exec_grade < 1)
		throw GradeTooHighException();
	if (_sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other)
: _name(other.getName()), _signed(other.getSigned()),
	_sign_grade(other.getSignGrade()),
	_exec_grade(other.getExecGrade())
{}

Form::~Form() {}

const std::string& Form::getName() const
{
	return (_name);
}

bool Form::getSigned() const
{
	return (_signed);
}

int Form::getSignGrade() const
{
	return (_sign_grade);
}

int Form::getExecGrade() const
{
	return (_exec_grade);
}

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _sign_grade)
		throw GradeTooLowException();
	_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low");
}

std::ostream& operator<<(std::ostream& str, const Form& f)
{
	str << "Form named " << f.getName()
		<< ", is: " << (f.getSigned() ? "" : "not ") << "signed"
		<< ", sign grade: " << f.getSignGrade()
		<< ", exec grade: " << f.getExecGrade() << std::endl;
	return (str);
}