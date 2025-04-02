/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:12:02 by ematon            #+#    #+#             */
/*   Updated: 2025/04/02 21:58:10 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#define MAX_CONTACTS 8
#define INDEX_QUERY "Enter valid contact index:"

class PhoneBook
{
	public:
		PhoneBook();
		int				Add();
		int				Search();
		unsigned int	nb_contacts;
		Contact			contacts[MAX_CONTACTS];

	private:
		std::string		FitIntoColumn(std::string str);
		void			PrintColumns(int i);
		bool			IsValidIndex(std::string input, int n);
};
