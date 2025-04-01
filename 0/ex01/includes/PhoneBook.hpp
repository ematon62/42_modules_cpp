/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:12:02 by ematon            #+#    #+#             */
/*   Updated: 2025/04/01 20:29:20 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#define MAX_CONTACTS 8
#define INVALID_FIELD "Contact info field cannot be empty"

class PhoneBook
{
	public:
		PhoneBook();
		void			Add();
		void			Search();

	private:
		unsigned int	nb_contacts;
		Contact			contacts[MAX_CONTACTS];
		t_contact_info	GetContactInfo();
};
