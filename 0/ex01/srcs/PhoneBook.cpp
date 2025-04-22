/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:34:30 by ematon            #+#    #+#             */
/*   Updated: 2025/04/22 15:48:36 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	nb_contacts = 0;
}

void PhoneBook::PrintColumns(int i)
{
	std::cout << std::setw(10) << i << "|";
	contacts[i].PrintColumns();
}

bool PhoneBook::IsValidIndex(std::string input, int n)
{
	return (input.size() == 1 && input[0] >= '0'
			&& input[0] < '8' && (input[0] - 48) < n);
}

int PhoneBook::Add()
{
	Contact	new_contact;

	new_contact.GetContactInfo();
	if (!new_contact.initialized)
		return (1);
	PhoneBook::contacts[PhoneBook::nb_contacts % 8] = new_contact;
	PhoneBook::nb_contacts += 1;
	return (0);
}

int PhoneBook::Search()
{
	std::string input;
	int			index;

	for (unsigned int i = 0; i < nb_contacts && i < 8; i++)
		PrintColumns(i);
	input[0] = 0;
	while (!IsValidIndex(input, nb_contacts))
	{
		std::cout << INDEX_QUERY << std::endl;
		if (!getline(std::cin, input))
			return (1);
	}
	index = input[0] - 48;
	contacts[index].PrintContactInfo();
	return (0);
}
