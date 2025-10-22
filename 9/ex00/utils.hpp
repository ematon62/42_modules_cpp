/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 21:20:37 by ematon            #+#    #+#             */
/*   Updated: 2025/10/21 18:38:03 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool isValidDateString(std::string& str);
void getDateInfo(struct s_date &date, std::string &str);
bool isValidDateInfo(struct s_date &date);
void printDate(struct s_date &date);
bool isBissextile(int year);
bool isValidLineFormat(std::string& line, size_t index);
bool isValidValueString(std::string& str);