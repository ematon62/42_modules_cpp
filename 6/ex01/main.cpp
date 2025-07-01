/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:47:52 by gross             #+#    #+#             */
/*   Updated: 2025/07/01 16:24:27 by gross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	std::cout << "Creating Data object, _name = \"jp\"\n";
	Data jp("jp");
	uintptr_t value = Serializer::serialize(&jp);
	std::cout << Serializer::deserialize(value)->getName() << std::endl;
	std::cout << "\nAdresses:\n";
	std::cout << &jp << std::endl;
	std::cout << Serializer::deserialize(value) << std::endl;
}