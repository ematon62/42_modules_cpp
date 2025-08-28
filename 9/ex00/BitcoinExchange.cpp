/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:49:37 by gross             #+#    #+#             */
/*   Updated: 2025/08/28 14:22:38 by gross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool operator<(const tm date1, const tm date2)
{
	return (date1.tm_year < date2.tm_year
		|| (date1.tm_year == date2.tm_year && date1.tm_mon < date2.tm_mon)
		|| (date1.tm_year == date2.tm_year && date1.tm_mon == date2.tm_mon && date1.tm_mday < date2.tm_mday));
}

void printDate(tm date)
{
	std::cout << date.tm_year << "-";
	std::cout << std::setfill('0') << std::setw(2)  << date.tm_mon;
	std::cout << "-";
	std::cout << std::setfill('0') << std::setw(2) << date.tm_mday;
}

bool isValidLineFormat(std::string& line, size_t index)
{
	return !(index == std::string::npos || index == 0 || line[index - 1] != ' ' || line[index + 1] != ' ');
}

bool isValidDateFormat(std::string &date_str)
{
	return (date_str.length() == 10
		&& (date_str[0] >= '0' && date_str[0] <= '9')
		&& (date_str[1] >= '0' && date_str[1] <= '9')
		&& (date_str[2] >= '0' && date_str[2] <= '9')
		&& (date_str[3] >= '0' && date_str[3] <= '9')
		&& date_str[4] == '-'
		&& (date_str[5] >= '0' && date_str[5] <= '9')
		&& (date_str[6] >= '0' && date_str[6] <= '9')
		&& date_str[7] == '-'
		&& (date_str[8] >= '0' && date_str[8] <= '9')
		&& (date_str[9] >= '0' && date_str[9] <= '9'));
}

bool BitcoinExchange::isValidDate(tm& date)
{
	tm first_date = (*(data.begin())).first;
	return (first_date < date);
}

bool isValidValue(const std::string& str, float& outValue) {
    std::istringstream iss(str);
    float value;

    iss >> value;

    if (str.length() > 4 || (!iss.fail() && iss.eof())) {
        if (value >= 0.0f && value <= 1000.0f) {
            outValue = value;
            return true;
        }
    }

    return false;
}

BitcoinExchange::BitcoinExchange() : data()
{
	std::string date_str;
	std::string value_str;
	tm			date;
	std::string	line;

	std::ifstream database(DATABASE);
	if (!database.good())
		throw DatabaseException();
	std::getline(database, line); //Pass first line defining columns
	
	while(std::getline(database, line))
	{
		date_str = line.substr(0, COMMA_POSITION);
		value_str = line.substr(COMMA_POSITION + 1, line.length());		
		strptime(date_str.c_str(), "%Y-%m-%d", &date);
		date.tm_year += 1900;
		date.tm_mon += 1;
		std::pair<tm, float> new_pair(date, strtof(value_str.c_str(), NULL));
		data.insert(new_pair);
	}
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::printValues(std::ifstream& input)
{
	std::string line;
	tm			date;
	float		value;

	std::getline(input, line); // Pass first line defining columns
	while (std::getline(input, line))
	{
		try
		{
			parseLine(line, date, value);
			printWithClosestExchangeRate(date, value);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}

void BitcoinExchange::parseLine(std::string &line, tm &date, float &value)
{
	size_t		index;
	std::string	date_str;
	std::string	value_str;

	index = line.find('|');
	if (!isValidLineFormat(line, index)) { //Check if line in "date | value" format
		std::cerr << line + ": ";
		throw InvalidInputException();
	}

	date_str = line.substr(0, index - 1);
	if (!isValidDateFormat(date_str))
		throw InvalidDateFormatException();
	strptime(date_str.c_str(), "%Y-%m-%d", &date);
	date.tm_year += 1900;
	date.tm_mon += 1;
	if (!isValidDate(date))
		throw InvalidDateException();
	value_str = line.substr(index + 2, line.length());
	value = strtof(value_str.c_str(), NULL);
	if (!isValidValue(value_str, value))
		throw InvalidValueException();
}

void BitcoinExchange::printWithClosestExchangeRate(const tm date, float value)
{

	float closest_value;

	std::map<tm, float>::iterator it = data.begin();
	std::map<tm, float>::iterator jt = it;
	while (it != data.end())
	{
		if (date < (*it).first)
			break;
		jt = it;
		it++;
	}

	closest_value = (*jt).second;
	printDate(date);
	std::cout << " => " << value << " = " << value * closest_value << std::endl;
}

const char* BitcoinExchange::DatabaseException::what() const throw()
{
	return ("Error ocurred when opening data.csv");
}

const char* BitcoinExchange::InvalidInputException::what() const throw()
{
	return ("Error: bad input");
}

const char* BitcoinExchange::InvalidDateFormatException::what() const throw()
{
	return ("Error: Invalid date format");
}

const char* BitcoinExchange::InvalidDateException::what() const throw()
{
	return ("Error: Date does not fit into database");
}

const char* BitcoinExchange::InvalidValueException::what() const throw()
{
	return ("Error: value must be a float or integer between 0 and 1000");
}