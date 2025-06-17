/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:42:13 by ematon            #+#    #+#             */
/*   Updated: 2025/06/17 11:29:55 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
		PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		PresidentialPardonForm(const PresidentialPardonForm& other);
	public:
		PresidentialPardonForm(const std::string& target);
		virtual ~PresidentialPardonForm();
		virtual void execute(Bureaucrat const & executor) const;
		void pardon() const;
		void printTarget() const;
};

#endif