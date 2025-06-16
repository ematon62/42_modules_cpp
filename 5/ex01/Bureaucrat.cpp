/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:14:45 by ematon            #+#    #+#             */
/*   Updated: 2025/06/16 17:44:17 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(int grade, const std::string& name)
: _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
: _name(other._name), _grade(other._grade)
{
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	std::cout << this->getName() << "'s grade has been increased.\n";
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	std::cout << this->getName() << "'s grade has been decreased.\n";
	_grade++;
}

void Bureaucrat::signForm(Form& f)
{
	try
	{
		f.beSigned(*this);
		std::cout << getName() << " signs " << f.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << getName() << " cannot sign " << f.getName()
			<< ". Reason: Bureaucrat's grade is " << getGrade()
			<< " and Form sign grade is " << f.getSignGrade() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat grade is too low");
}

std::ostream& operator<<(std::ostream &str, const Bureaucrat &b)
{
	str << b.getName() + ", bureaucrat grade " << b.getGrade() << ".\n";
	return (str);
}