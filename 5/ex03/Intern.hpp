/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:40:31 by ematon            #+#    #+#             */
/*   Updated: 2025/06/17 16:01:14 by ematon           ###   ########.fr       */
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
	public:
		Intern();
		~Intern();
		AForm* makeForm(const std::string &form_type, const std::string& target) const;

	class UnknownFormException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

#endif