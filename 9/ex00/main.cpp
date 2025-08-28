/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:25:49 by gross             #+#    #+#             */
/*   Updated: 2025/08/28 14:08:51 by gross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << BAD_ARGS << std::endl;
		return 1;
	}

	std::ifstream input(argv[1]);
	if (!input)
	{
		perror("open");
		return 1;
	}
	
	try
	{
		// tm date1;
		// date1.tm_year = 2009;
		// date1.tm_mon = 01;
		// date1.tm_mday = 9;
		// tm date2;
		// date2.tm_year = 2009;
		// date2.tm_mon = 01;
		// date2.tm_mday = 02;
		
		// std::cout << (date1 < date2) << std::endl;
		BitcoinExchange	data;
		data.printValues(input);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}