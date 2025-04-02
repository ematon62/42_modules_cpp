/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:35:14 by ematon            #+#    #+#             */
/*   Updated: 2025/04/02 21:43:34 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#define INPUT_MSG "Please enter either of these commands: ADD/SEARCH/EXIT"
#define ERR_MSG "Warning: EOF detected"

bool is_whitespace(std::string str)
{
	for (unsigned int i = 0; i <= str.size(); i++)
	{
		if (str[i] && !(str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r')))
			return (false);
	}
	return (true);
}

int main(void)
{
	PhoneBook	pb;
	std::string	input;

	while (1)
	{
		std::cout << INPUT_MSG << std::endl;
		if (!std::getline(std::cin, input))
			break;
		if (input == "ADD")
		{
			if (pb.Add())
				break;
		}
		else if (input == "SEARCH" && pb.nb_contacts)
		{
			if (pb.Search())
				break;
		}
		else if (input == "EXIT")
			break;
	}
	return (0);
}
