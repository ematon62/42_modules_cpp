/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:01:39 by gross             #+#    #+#             */
/*   Updated: 2025/08/28 16:02:25 by gross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <string>
#include <iostream>

class RPN {
	private:
		std::stack<int>	_stack;
		std::string		_input;

		RPN();
		RPN(RPN& other);
		RPN& operator=(RPN& other);

	public:
		RPN(const char *input);
		~RPN();

		void calculate();
		void printResult();
		void handleOperation(char c);
		int& safeTop();

	class StackEmptyException : public std::exception
	{
		virtual const char * what() const throw();
	};

	class DivideByZeroException : public std::exception
	{
		virtual const char * what() const throw();
	};

	class TooManyOperandsException : public std::exception
	{
		virtual const char * what() const throw();
	};
};