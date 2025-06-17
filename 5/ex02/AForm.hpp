/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:10:16 by ematon            #+#    #+#             */
/*   Updated: 2025/06/17 13:42:27 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int			_exec_grade;
		AForm();
		AForm& operator=(const AForm& other);
	public:
		AForm(const std::string& name, int sign_grade, int exec_grade);
		AForm(const AForm &other);
		virtual ~AForm() = 0;
		const std::string& getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;
		void beSigned(const Bureaucrat& b);
		virtual void execute(Bureaucrat const & executor) const = 0;
		void verify(Bureaucrat const & executor) const;
		virtual void printTarget() const = 0;

		class NotSignedException : public std::exception
		{
			virtual const char* what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};


		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& str, const AForm& f);

#endif