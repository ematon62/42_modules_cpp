/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:41:05 by ematon            #+#    #+#             */
/*   Updated: 2025/06/25 22:05:29 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>

typedef enum e_type
{
	ELSE,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
}	t_type;

typedef struct s_conv_info
{
	t_type	type;
	double	value;
	bool	is_printable;
	bool	int_overflow;
	bool	float_overflow;
}	t_conv_info;

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
	public:
		static void convert(const std::string& str);
};

t_type get_scalar_type(const std::string& str);
t_type get_pseudo_type(const std::string& str);
t_conv_info check_overflows(t_type initial_type, const std::string &str);
#endif