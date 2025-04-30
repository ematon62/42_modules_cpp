/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grossviche <grossviche@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:14:32 by grossviche        #+#    #+#             */
/*   Updated: 2025/04/30 14:16:20 by grossviche       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Animal.hpp"
#pragma once

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();

		virtual void makeSound() const;
		std::string getType() const;
};