/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grossviche <grossviche@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 21:37:00 by ematon            #+#    #+#             */
/*   Updated: 2025/04/16 15:17:16 by grossviche       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl guy;
	guy.complain("DEBUG");
	guy.complain("INFO");
	guy.complain("WARNING");
	guy.complain("ERROR");

	std::cout << std::endl;
	guy.complain("On est au quick wesh");
	guy.complain("oe c greg");
	guy.complain("aaaaaaaaaaaaaaaa");
	guy.complain("caca");
}
