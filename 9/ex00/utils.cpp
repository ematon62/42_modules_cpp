/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 21:20:03 by ematon            #+#    #+#             */
/*   Updated: 2025/09/25 21:42:51 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool isBissextile(int year)
{
    if (year % 4 != 0)
        return false; 
    else if (year % 100 != 0)
        return true;  
    else if (year % 400 == 0)
        return true;
    return false;
}

bool isValidDateString(std::string& str)
{
    int j = 0;
    int i = 0;

    while (str[i] && str[i] != '-')
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return false;
        i++;
    }
    if (i == 0) return false;

    i++;

    while (str[i + j] && str[i + j] != '-')
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return false;
        j++;
    }
    if (j < 1) return false;

    i += j + (str[i +j] == '-' ? 1 : 0);
    j = 0;
    while (str[i + j] && str[i + j] != '-')
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return false;
        j++;
    }
    if (j < 1) return false;

    return true;
}

void getDateInfo(struct s_date &date, std::string &str)
{
    int i = 0;
    int temp = 0;
    while (str[temp + i] && str[temp + i] != '-')
        i++;
    date.year = atoi(str.substr(0, i).c_str());

    temp = i + 1;
    i = 0;
    while (str[temp + i] && str[temp + i] != '-')
        i++;
    date.month = atoi(str.substr(temp, i).c_str());

    temp += i + 1;
    i = 0;
    while (str[temp + i])
        i++;

    date.day = atoi(str.substr(temp, i).c_str());
}

bool isValidDateInfo(struct s_date &date)
{
    if (!(date.day >= 0 && date.day <= 31))
        return false;
    if (!(date.month >= 1 && date.month <= 12))
        return false;

    switch(date.month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            break;
        case 2:
            if (date.day > 29 || (!isBissextile(date.year) && date.day == 29))
                return false;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (date.day > 30) return false;
            break;
        default:
            return false;
    }

    return true;
}

bool operator<(struct s_date date1, struct s_date date2)
{
	return (date1.year < date2.year
		|| (date1.year == date2.year && date1.month < date2.month)
		|| (date1.year == date2.year && date1.year == date2.month && date1.day < date2.day));
}

void printDate(struct s_date &date)
{
	std::cout << date.year << "-";
	std::cout << std::setfill('0') << std::setw(2)  << date.month;
	std::cout << "-";
	std::cout << std::setfill('0') << std::setw(2) << date.day;
}

bool isValidLineFormat(std::string& line, size_t index)
{
	return !(index == std::string::npos || index == 0 || line[index - 1] != ' ' || line[index + 1] != ' ');
}