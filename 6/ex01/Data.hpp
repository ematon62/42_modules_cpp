/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:41:05 by ematon            #+#    #+#             */
/*   Updated: 2025/06/27 15:43:17 by gross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data
{
	private:
		std::string	_name;
	public:
		Data();
		Data(const std::string& name);
		Data(const Data& other);
		Data& operator=(const Data& other);
		~Data();
		std::string getName() const;
};

#endif