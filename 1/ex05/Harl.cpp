/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grossviche <grossviche@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:24:52 by grossviche        #+#    #+#             */
/*   Updated: 2025/04/16 15:18:18 by grossviche       ###   ########.fr       */
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
    this->levels[0] = "DEBUG";
    this->levels[1] = "INFO";
    this->levels[2] = "WARNING";
    this->levels[3] = "ERROR";
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
    for (int i = 0; i < 4; i++)
    {
        if (level == this->levels[i])
        {
            (this->*(complaints[i]))();
            return;
        }
    }
    (this->*(complaints[level.size() % 4]))();
}