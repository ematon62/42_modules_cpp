/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:34:17 by ematon            #+#    #+#             */
/*   Updated: 2025/04/01 20:16:46 by ematon           ###   ########.fr       */
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

Contact::Contact(t_contact_info c_info)
{
	infos = c_info;
}