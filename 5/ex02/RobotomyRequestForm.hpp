/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:48:49 by ematon            #+#    #+#             */
/*   Updated: 2025/06/17 14:29:21 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include <cstdlib>

#define ROBOT_SUCCESS "'s robotomy was a success."
#define ROBOT_FAIL "'s robotomy was a failure."

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
		RobotomyRequestForm();
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		RobotomyRequestForm(const RobotomyRequestForm& other);
	public:
		RobotomyRequestForm(const std::string& target);
		virtual ~RobotomyRequestForm();
		virtual void execute(Bureaucrat const & executor) const;
		void robotomy() const;
		void printTarget() const;
};

#endif