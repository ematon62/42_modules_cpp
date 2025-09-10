/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:49:37 by gross             #+#    #+#             */
/*   Updated: 2025/08/28 16:01:57 by gross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool isOperator(char c)
{
	return (c == '+'
		|| c == '-'
		|| c == '*'
		|| c == '/');
}

RPN::RPN() {}

RPN::RPN(const char *input) : _stack(), _input(input) {}

RPN::~RPN() {}

void RPN::calculate()
{
	unsigned int i = 0;

	while (i < _input.length())
	{
		if (std::isspace(_input[i]))
		{
			while (std::isspace(_input[i]))
				i++;
			continue;
		}
		else if (std::isdigit(_input[i]))
		{
			if (_input[i + 1] && !std::isspace(_input[i + 1]))
				throw NotADigitException();
			_stack.push(_input[i] - 48);
			i++;
		}
		else if (isOperator(_input[i]))
		{
			handleOperation(_input[i]);
			i++;
		}
		else
			throw NotADigitException();
	}
	
	printResult();
}

void RPN::printResult()
{
	try
	{
		if (_stack.size() > 1)
			throw TooManyOperandsException();
		std::cout << safeTop() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int& RPN::safeTop()
{
	if (_stack.size() == 0)
		throw StackEmptyException();
	return _stack.top();
}

void RPN::handleOperation(char c)
{
	int x;
	int y;
	int result;

	y = safeTop();
	_stack.pop();
	x = safeTop();
	_stack.pop();

	if (c == '+')
		result = x + y;
	else if (c =='-')
		result = x - y;
	else if (c == '*')
		result = x * y;
	else
	{
		if (y == 0)
			throw DivideByZeroException();
		result = x / y;
	}
	
	_stack.push(result);
}

const char * RPN::StackEmptyException::what() const  throw()
{
	return "Error: not enough operands";
}

const char * RPN::DivideByZeroException::what() const throw()
{
	return "Error: dividing by zero";
}

const char * RPN::TooManyOperandsException::what() const throw()
{
	return "Error: too many operands";
}

const char * RPN::NotADigitException::what() const throw()
{
	return "Error: Program only accepts digits between 0 and 9";
}