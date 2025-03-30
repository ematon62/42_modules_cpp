/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:50:24 by ematon            #+#    #+#             */
/*   Updated: 2025/03/30 14:53:20 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	say_loudly(char *str)
{
	for (int j = 0; str[j]; j++)
	{
		if (str[j] >= 'a' && str[j] <= 'z')
			str[j] -= 32;
		std::cout << str[j];
	}
}

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "caca";
	else
	{
		for (int i = 1; argv[i]; i++)
			say_loudly(argv[i]);
	}
	std::cout << "\n";
}