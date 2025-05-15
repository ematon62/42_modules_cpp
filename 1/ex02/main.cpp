/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 21:37:00 by ematon            #+#    #+#             */
/*   Updated: 2025/05/15 11:03:44 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << "..................String memory adress: "
		<< &brain << std::endl;
	std::cout << "Memory address pointed to by stringPTR: "
		<< stringPTR << std::endl;
	std::cout << "Memory address pointed to by stringREF: "
		<< &stringREF << std::endl;

	std::cout << ".................................String value: "
		<< brain << std::endl;
	std::cout << "Value of the variable pointed to by stringPTR: "
		<< *stringPTR << std::endl;
	std::cout << "Value of the variable pointed to by stringREF: "
		<< stringREF << std::endl;
	return (0);
}
