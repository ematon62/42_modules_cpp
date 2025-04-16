/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grossviche <grossviche@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 21:37:00 by ematon            #+#    #+#             */
/*   Updated: 2025/04/16 16:16:22 by grossviche       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

levelCode hash_level(std::string level)
{
	if (level == "DEBUG")
		return debug;	
	if (level == "INFO")
		return info;
	if (level == "WARNING")
		return warning;
	if (level == "ERROR")
		return error;
	return unknown;
}

void print_levels(Harl guy, int n)
{
	while (n < 5)
	{
		if (n < 4)
		{
			std::cout << "[" + guy.levels[n] + "]\n";
			guy.complain(guy.levels[n]);
			std::cout << std::endl;
		}
		switch (n)
		{
			case debug:
			{
				n++;
				break;
			}
			case info:
			{
				n++;
				break;
			}
			case warning:
			{
				n++;
				break;
			}
			case error:
			{
				n += 2;
				break;
			}
			default:
			{
				std::cout << "[Probably complaining about some random shit]\n";
				n++;
				break;
			}
		}
	}
}

int main(int argc, char **argv)
{
	Harl guy;
	
	if (argc != 2)
	{
		std::cout << "./Harlfilter [LEVEL]\n";
		return (1);
	}

	std::string level(argv[1]);
	print_levels(guy, hash_level(level));
	return (0);
}
