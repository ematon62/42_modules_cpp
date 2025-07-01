/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:48:05 by ematon            #+#    #+#             */
/*   Updated: 2025/07/01 14:24:36 by gross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool isnum(char c)
{
	return ((c >= '0' && c <= '9'));
}

t_type get_pseudo_type(const std::string& str)
{
	if (str == "nanf" || str == "-inff" || str == "inff" || str == "+inff")
		return (FLOAT);
	else if (str == "nan" || str == "-inf" || str == "inf" || str == "+inf")
		return (DOUBLE);
	return (ELSE);
}


t_type get_scalar_type(const std::string &str, size_t n)
{
	t_type			type = INT;
	unsigned int	i = 0;
	bool			has_numbers = false;
	
	if (str[i] == '+' || str[i] == '-')
		i++;
	for (; str[i]; i++)
	{
		if (str[i] == '.' && type != DOUBLE)
			type = DOUBLE;
		else if (!isnum(str[i]) && (i != n - 1 || str[i] != 'f'))
			return (ELSE);
		else if (isnum(str[i]))
			has_numbers = true;
	}
	if (!has_numbers)
		return (ELSE);
	if (str[i - 1] == 'f')
		type = FLOAT;
	return (type);
}

t_conversion get_info(t_type type, const std::string& str)
{
	t_conversion info;
	
	info.overflow_test = atof(str.c_str());
	info.possible = true;
	info.overflow = false;
	switch(type)
	{
		case (CHAR):
			info.char_value = str[1];
			info.int_value = static_cast<int>(info.char_value);
			info.fl_value = static_cast<float>(info.char_value);
			info.dbl_value = static_cast<double>(info.char_value);
			break;
		case (INT):
			if (info.overflow_test > std::numeric_limits<int>::max()
				|| info.overflow_test < std::numeric_limits<int>::min())
				info.overflow = true;
			info.int_value = atoi(str.c_str());
			info.char_value = static_cast<char>(info.int_value);
			info.fl_value = static_cast<float>(info.int_value);
			info.dbl_value = static_cast<double>(info.int_value);
			break;
		case(FLOAT):
			if (info.overflow_test == std::numeric_limits<float>::infinity()
				|| info.overflow_test == -std::numeric_limits<float>::infinity()
				|| str == "nanf")
				info.possible = false;
			else if (info.overflow_test > std::numeric_limits<float>::max()
				|| info.overflow_test < -std::numeric_limits<float>::min())
				info.overflow = true;
			info.dbl_value = atof(str.c_str());
			info.char_value = static_cast<char>(info.dbl_value);
			info.int_value = static_cast<int>(info.dbl_value);
			info.fl_value = static_cast<float>(info.dbl_value);
			// std::cout << info.dbl_value << std::endl;
			// std::cout << info.fl_value << std::endl;
			break;
		case(DOUBLE):
			if (info.overflow_test == std::numeric_limits<double>::infinity()
				|| info.overflow_test == -std::numeric_limits<float>::infinity()
				|| str == "nan")
				info.possible = false;
			info.dbl_value = atof(str.c_str());
			info.char_value = static_cast<char>(info.dbl_value);
			info.int_value = static_cast<int>(info.dbl_value);
			info.fl_value = static_cast<float>(info.dbl_value);
			break;
		default:
			break;
	}
	return (info);
}

void print_char(t_conversion info)
{
	std::cout << "char: ";
	if (!info.possible)
		std::cout << "impossible\n";
	else if (info.char_value >= 0 && info.char_value <= 32)
		std::cout << "non printable\n";
	else
		std::cout << info.char_value << std::endl;
}

void print_int(t_conversion info)
{
	std::cout << "int: ";
	if (!info.possible)
		std::cout << "impossible\n";
	else if (info.overflow_test > std::numeric_limits<int>::max()
		|| info.overflow_test < std::numeric_limits<int>::min())
		std::cout << "overflow\n";
	else
		std::cout << info.int_value << std::endl;
}

void print_float(t_conversion info)
{
	std::cout.precision(1);
	std::cout << std::fixed;
	std::cout << "float: " << info.fl_value << "f\n";
}

void print_double(t_conversion info)
{
	std::cout.precision(1);
	std::cout << std::fixed;
	std::cout << "double: " << info.dbl_value << std::endl;
}

void print_info(t_conversion info)
{
	if (info.overflow)
	{
		std::cout << "Overflow\n";
		return ;
	}
	print_char(info);
	print_int(info);
	print_float(info);
	print_double(info);
}

void ScalarConverter::convert(const std::string& str)
{
	t_type type;
	size_t n = str.length();

	type = get_pseudo_type(str);
	if (type == ELSE)
	{
		if (n == 3 && str[0] == '\'' && str[2] == '\'')
			type = CHAR;
		else
			type = get_scalar_type(str, n);
	}
	if (type == ELSE)
	{
		std::cout << "Input does not represent a literal\n";
		return ;
	}
	t_conversion	info = get_info(type, str);
	print_info(info);
}