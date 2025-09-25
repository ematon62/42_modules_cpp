/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:49:37 by gross             #+#    #+#             */
/*   Updated: 2025/09/25 21:44:50 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

bool BitcoinExchange::isValidYear(struct s_date& date)
{
	struct s_date first_date = (*(data.begin())).first;
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
	std::string	line;
	struct s_date date;

	std::ifstream database(DATABASE);
	if (!database.good())
		throw DatabaseException();
	std::getline(database, line); //Pass first line defining columns
	
	while(std::getline(database, line))
	{
		std::string date_str = line.substr(0, COMMA_POSITION);
		std::string value_str = line.substr(COMMA_POSITION + 1, line.length());
		getDateInfo(date, date_str);
		std::pair<struct s_date, float> new_pair(date, strtof(value_str.c_str(), NULL));
		data.insert(new_pair);
	}
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::exchange(std::ifstream& input)
{
	std::string line;
	struct s_date	date;
	float		value;

	std::getline(input, line);
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

void BitcoinExchange::parseLine(std::string &line, struct s_date &date, float &value)
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
	if (!isValidDateString(date_str))
		throw InvalidDateFormatException();
	getDateInfo(date, date_str);
	if (!isValidDateInfo(date) || !isValidYear(date))
		throw InvalidDateException();
	value_str = line.substr(index + 2, line.length());
	value = strtof(value_str.c_str(), NULL);
	if (!isValidValue(value_str, value))
		throw InvalidValueException();
}

void BitcoinExchange::printWithClosestExchangeRate(struct s_date date, float value)
{

	float closest_value;

	std::map<struct s_date, float>::iterator it = data.begin();
	std::map<struct s_date, float>::iterator jt = it;
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