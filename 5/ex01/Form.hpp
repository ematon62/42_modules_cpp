/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:10:16 by ematon            #+#    #+#             */
/*   Updated: 2025/06/16 17:42:18 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_sign_grade;
		const int			_exec_grade;
		Form();
		Form& operator=(const Form& other);
	public:
		Form(const std::string& name, int sign_grade, int exec_grade);
		Form(const Form &other);
		~Form();
		const std::string& getName() const;
		bool getSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;
		void beSigned(const Bureaucrat& b);

		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& str, const Form& f);

#endif