/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:25:49 by gross             #+#    #+#             */
/*   Updated: 2025/09/06 18:24:20 by gross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static int	is_overflow(char *str, int i, int n)
{
	if (!str[i])
		return (0);
	else if ((n > 0 && n * 10 + str[i] - '0' < n)
		|| (n < 0 && n * 10 + str[i] - '0' > n))
		return (1);
	return (is_overflow(str, i + 1, n * 10 + str[i] - '0'));
}

static int	is_integer(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (str[i])
	{
		if (!i && (str[i] == '-' || str[i] == '+'))
		{
			if (str[0] == '-')
				sign *= -1;
			if (!isdigit(str[i + 1]))
				return (0);
		}
		else if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (!is_overflow(str, 0, 0));
}

/*
- Only positive integers
- No overflow
- 
*/
bool isValidInput(int argc, char **argv)
{
	int	intege;

	for (int i = 1; i < argc; i++)
	{
		intege = atoi(argv[i]);
		if (!is_integer(argv[i]) || intege < 0)
		{
			return (false);
		}
	}
	return (true);
}

double getElapsedTime(clock_t start, clock_t end)
{
	return static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

int main(int argc, char **argv)
{
	clock_t start_vec;
	clock_t end_vec;
	clock_t start_deq;
	clock_t end_deq;

	if (argc == 1 || !isValidInput(argc, argv))
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	PmergeMe algo;
	algo.saveOriginalInput(argc, argv);

	start_vec = clock();
	algo.sortVector();
	end_vec = clock();

	start_deq = clock();
	algo.sortDeque();
	end_deq = clock();

	std::cout << "Before: ";
	algo.printOriginal();
	std::cout << std::endl;

	std::cout << "After: ";
	algo.printVector();
	std::cout << std::endl;
	
	std::cout << std::setprecision(6);
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector: "
		<< getElapsedTime(start_vec, end_vec) << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque: "
		<< getElapsedTime(start_deq, end_deq) << std::endl;
}	