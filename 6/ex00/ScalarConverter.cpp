/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:48:05 by ematon            #+#    #+#             */
/*   Updated: 2025/06/25 22:30:03 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool isnum(char c)
{
	return ((c >= '0' && c <= '9'));
}

t_type simple_cases(const std::string& str, size_t n)
{
	if (n <= 1)
		return (CHAR);
	else if ((isnum(str[0]) && isnum(str[1]) )
		|| ( (str[0] == '+' || str[0] == '-') && isnum(str[1]) ))
		return (INT);
	else if ((isnum(str[0]) && str[1] == '.') || (isnum(str[1]) && str[0] == '.'))
		return (DOUBLE);
	return (ELSE);
}

t_type get_pseudo_type(const std::string& str)
{
	if (str == "nanf" || str == "-inff" || str == "inff" || str == "+inff")
		return (FLOAT);
	else if (str == "nan" || str == "-inf" || str == "inf" || str == "+inf")
		return (DOUBLE);
	return (ELSE);
}

t_conv_info check_overflows(t_type type, const std::string &str)
{
	t_conv_info info;
	
	info.int_overflow = false;
	info.float_overflow = false;
	info.is_printable = true;
	if (type == INT
		&& (info.value < std::numeric_limits<int>::min()
		|| info.value > std::numeric_limits<int>::max()))
		info.int_overflow = true;
	return (info);
}

t_type get_scalar_type(const std::string &str, size_t n)
{
	t_type			type = CHAR;
	unsigned int	i = 0;
	bool			has_numbers = false;
	
	type = INT;
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

void ScalarConverter::convert(const std::string& str)
{
	t_type type;
	size_t n = str.length();

	if (n <= 2)
		type = simple_cases(str, n);
	else
	{
		type = get_pseudo_type(str);
		if (type == ELSE)
			type = get_scalar_type(str, n);
	}
	t_conv_info conv_info = check_overflows(type, str);
	(void)conv_info;
	switch(type)
	{
		case ELSE:
			std::cout << "else\n";
			break;
		case CHAR:
			std::cout << "char\n";
			break;
		case INT:
			std::cout << "int\n";
			break;
		case FLOAT:
			std::cout << "float\n";
			break;
		case DOUBLE:
			std::cout << "double\n";
			break;
	}
}