/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:34:30 by ematon            #+#    #+#             */
/*   Updated: 2025/04/01 20:46:54 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	nb_contacts = 0;
}

t_contact_info PhoneBook::GetContactInfo()
{
	t_contact_info	contact_info;
	std::string		input;
	unsigned int	i;

	i = 0;
	while (i < 5)
	{
		std::cout << infos[i];
		getline(std::cin, input);
		while (!input[0])
		{
			std::cerr << INVALID_FIELD << std::endl;
			std::cout << infos[i];
			getline(std::cin, input);
		}
		switch(i)
		{
			case 0:
				contact_info.first_name = input;
			case 1:
				contact_info.last_name = input;
			case 2:
				contact_info.nickname = input;
			case 3:
				contact_info.phone_number = input;
			case 4:
				contact_info.secret = input;
		}
		i++;
	}
	return (contact_info);
}

void PhoneBook::Add()
{
	t_contact_info	c_info;

	c_info = PhoneBook::GetContactInfo();
	PhoneBook::contacts[PhoneBook::nb_contacts % 8] = Contact(c_info);
	PhoneBook::nb_contacts += 1;
}

void PhoneBook::Search(void)
{
	unsigned int	i;

	i = 0;
	while (i <= nb_contacts - 1 && i <= 7)
	{
		std::cout << contacts[i].infos.first_name << std::endl;
		i++;
	}
}
