/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:40:31 by ematon            #+#    #+#             */
/*   Updated: 2025/06/18 12:35:40 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
	private:
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		AForm* (Intern::*_makers[3])(const std::string& target);
		AForm* makeShrubbery(const std::string& target);
		AForm* makeRobotomy(const std::string& target);
		AForm* makePardon(const std::string& target);
	public:
		Intern();
		~Intern();
		AForm* makeForm(const std::string &form_type, const std::string& target);

	class UnknownFormException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

#endif