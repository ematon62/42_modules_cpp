/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:17:04 by ematon            #+#    #+#             */
/*   Updated: 2025/04/01 20:25:31 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

const std::string infos[] = {"First name:", "Last name:", "Nickname:", \
				"Phone number:", "Secret:"};

typedef struct ContactInfo
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string secret;
}	t_contact_info;


class Contact
{
	public:
		Contact();
		Contact(t_contact_info c_info);
		t_contact_info infos;
};