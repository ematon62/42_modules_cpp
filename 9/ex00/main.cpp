/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:25:49 by gross             #+#    #+#             */
/*   Updated: 2025/10/22 10:06:23 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

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
		BitcoinExchange	data;
		data.exchange(input);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}