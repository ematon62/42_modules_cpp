/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grossviche <grossviche@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:24:52 by grossviche        #+#    #+#             */
/*   Updated: 2025/04/16 14:43:52 by grossviche       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
    std::cout << "Harl instance created\n";
    this->complaints[0] = &Harl::debug;
    this->complaints[1] = &Harl::info;
    this->complaints[2] = &Harl::warning;
    this->complaints[3] = &Harl::error;
}

Harl::~Harl()
{
    std::cout << "Harl instance destroyed\n";
}

void Harl::debug()
{
    std::cout << DEBUG;
}

void Harl::info()
{
    std::cout << INFO;
}

void Harl::warning()
{
    std::cout << WARNING;
}

void Harl::error()
{
    std::cout << ERROR;
}

void Harl::complain(std::string level)
{
    (this->*(complaints[level.size() % 4]))();
}