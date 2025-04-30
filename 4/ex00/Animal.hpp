/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grossviche <grossviche@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:14:32 by grossviche        #+#    #+#             */
/*   Updated: 2025/04/30 14:47:24 by grossviche       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#pragma once

class Animal
{
	public:
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		~Animal();

		virtual void makeSound() const;
		std::string getType() const;
	protected:
		std::string type;
};