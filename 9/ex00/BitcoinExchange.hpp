/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:01:39 by gross             #+#    #+#             */
/*   Updated: 2025/10/21 18:50:32 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

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

struct s_date {
	int year;
	int day;
	int month;

	bool operator<(const struct s_date& date2) const
	{
		if (this->year != date2.year) return this->year < date2.year;
		if (this->month != date2.month) return this->month < date2.month;
		return this->day < date2.day;
	}

	bool operator<=(const struct s_date& date2) const
	{
		if (this->year != date2.year) return this->year <= date2.year;
		if (this->month != date2.month) return this->month <= date2.month;
		return this->day <= date2.day;
	}
};

class BitcoinExchange {
	private:
		BitcoinExchange(BitcoinExchange& other);
		BitcoinExchange& operator=(BitcoinExchange& other);
		std::map<struct s_date, float> data;
	
		public:
		BitcoinExchange();
		~BitcoinExchange();
		void exchange(std::ifstream &input);
		void parseLine(std::string &line, struct s_date& date, float& value);
		void printWithClosestExchangeRate(struct s_date date, float value);
		bool isValidYear(struct s_date date);

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

#endif