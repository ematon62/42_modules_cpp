/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:34:17 by ematon            #+#    #+#             */
/*   Updated: 2025/04/22 15:48:05 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	infos.first_name = "undefined";
	infos.last_name = "undefined";
	infos.nickname = "undefined";
	infos.phone_number = "undefined";
	infos.secret = "undefined";
}

void Contact::GetContactInfo()
{
	std::string		input;

	initialized = false;
	std::cout << FIELD_QUERY << std::endl;
	for (unsigned int i = 0; i < 5; i++)
	{
		input[0] = 0;
		while (!input[0] || is_whitespace(input))
		{
			std::cout << info_prompt[i];
			if (!getline(std::cin, input))
				return ;
		}
		switch(i)
		{
			case 0:
				infos.first_name = input;
			case 1:
				infos.last_name = input;
			case 2:
				infos.nickname = input;
			case 3:
				infos.phone_number = input;
			case 4:
				infos.secret = input;
		}
	}
	initialized = true;
}

void	Contact::PrintContactInfo()
{
	std::cout << infos.first_name << std::endl;
	std::cout << infos.last_name << std::endl;
	std::cout << infos.nickname << std::endl;
	std::cout << infos.phone_number << std::endl;
	std::cout << infos.secret << std::endl;
}

std::string	Contact::FitIntoColumn(std::string str)
{
	std::string smaller_str;

	smaller_str = str;
	if (smaller_str.length() > 10)
	{
		smaller_str[9] = '.';
		for (int i = 10; smaller_str[i]; i++)
			smaller_str[i] = '\0';
	}
	return (smaller_str);
}

void	Contact::PrintColumns()
{
	std::cout << std::setw(10) << FitIntoColumn(infos.first_name) << "|";
	std::cout << std::setw(10) << FitIntoColumn(infos.last_name) << "|";
	std::cout << std::setw(10) << FitIntoColumn(infos.nickname) << std::endl;
}