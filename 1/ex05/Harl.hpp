/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 13:21:38 by grossviche        #+#    #+#             */
/*   Updated: 2025/05/15 11:24:55 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#pragma once

#define DEBUG "I love having extra bacon for my \
7XL-double-cheese-triple-pickle-special-\
ketchup burger. I really do!\n"

#define INFO "I cannot believe adding extra bacon costs more money.\
You didnt put enough bacon in my burger! \
If you did, I wouldnt be asking for more!\n"

#define WARNING "I think I deserve to have some extra bacon for free. \
Ive been coming for years, \
whereas you started working here just last month.\n"

#define ERROR "This is unacceptable! I want to speak to the manager now.\n"


class Harl
{
    private:
        void debug();
        void info();
        void warning();
        void error();

    public:
        Harl();
        ~Harl();
        void (Harl::*complaints[4])();
        std::string  levels[4];
        void complain(std::string level);
};