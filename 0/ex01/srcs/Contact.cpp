/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:34:17 by ematon            #+#    #+#             */
/*   Updated: 2025/04/02 21:56:51 by ematon           ###   ########.fr       */
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

	infos.initialized = false;
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
	infos.initialized = true;
}

void	Contact::PrintContactInfo()
{
	std::cout << infos.first_name << std::endl;
	std::cout << infos.last_name << std::endl;
	std::cout << infos.nickname << std::endl;
	std::cout << infos.phone_number << std::endl;
	std::cout << infos.secret << std::endl;
}