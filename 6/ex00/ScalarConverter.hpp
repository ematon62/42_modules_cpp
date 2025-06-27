/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:41:05 by ematon            #+#    #+#             */
/*   Updated: 2025/06/27 14:34:50 by gross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cstdlib>

typedef enum e_type
{
	ELSE,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
}	t_type;

typedef struct s_conversion
{
	t_type	type;
	double	overflow_test;
	char	char_value;
	int		int_value;
	float	fl_value;
	double	dbl_value;
	bool	overflow;
	bool	possible;
}	t_conversion;

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
t_conversion check_overflows(t_type initial_type, const std::string &str);
#endif