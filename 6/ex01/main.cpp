/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:47:52 by gross             #+#    #+#             */
/*   Updated: 2025/06/29 18:30:03 by gross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	std::cout << "Creating Data object, _name = \"jp\"\n";
	Data jp("jp");
	uintptr_t caca = Serializer::serialize(&jp);
	std::cout << Serializer::deserialize(caca)->getName() << std::endl;
	std::cout << &jp << std::endl;
	std::cout << Serializer::deserialize(caca) << std::endl;
}