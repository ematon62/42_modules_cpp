/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:17:04 by ematon            #+#    #+#             */
/*   Updated: 2025/04/02 21:55:01 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>

#define FIELD_QUERY "Enter non-empty field:"

const std::string info_prompt[] = {"First name:", "Last name:", "Nickname:", \
				"Phone number:", "Secret:"};

typedef struct ContactInfo
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string secret;
	bool		initialized;
}	t_contact_info;

class Contact
{
	public:
		Contact();
		void GetContactInfo();
		void PrintContactInfo();
		t_contact_info infos;
};


bool is_whitespace(std::string str);