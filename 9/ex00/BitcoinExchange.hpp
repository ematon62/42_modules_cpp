/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:01:39 by gross             #+#    #+#             */
/*   Updated: 2025/08/28 14:17:25 by gross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <sstream>
#include <limits>
#include <cctype>

#define BAD_ARGS "Error: Bad number of arguments [./btc input_file]"
#define DATABASE "data.csv"
#define COMMA_POSITION 10

class BitcoinExchange {
	private:
		BitcoinExchange(BitcoinExchange& other);
		BitcoinExchange& operator=(BitcoinExchange& other);
		std::map<tm, float> data;
	
		public:
		BitcoinExchange();
		~BitcoinExchange();
		void printValues(std::ifstream &input);
		void parseLine(std::string &line, tm& date, float& value);
		void printWithClosestExchangeRate(tm date, float value);
		bool isValidDate(tm &date);

	class DatabaseException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class InvalidInputException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class InvalidDateFormatException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class InvalidDateException : public std::exception
	{
		virtual const char* what() const throw();
	};

	class InvalidValueException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

bool operator<(const tm date1, const tm date2);