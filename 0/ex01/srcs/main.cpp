/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:35:14 by ematon            #+#    #+#             */
/*   Updated: 2025/04/01 20:25:15 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#define INPUT_MSG "Please enter either of these commands: ADD/SEARCH/EXIT"
#define ERR_MSG "Warning: EOF detected"

int main(void)
{
	PhoneBook	pb;
	std::string	input;

	while (1)
	{
		std::cout << INPUT_MSG << std::endl;
		if (!std::getline(std::cin, input))
		{
			std::cerr << ERR_MSG << std::endl;
			return (1);
		}
		if (input == "ADD")
			pb.Add();
		else if (input == "SEARCH")
			pb.Search();
		else if (input == "EXIT")
			break ;
	}
	return (0);
}
