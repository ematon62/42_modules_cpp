/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:49:37 by gross             #+#    #+#             */
/*   Updated: 2025/09/06 18:24:41 by gross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void PmergeMe::saveOriginalInput(int argc, char **argv)
{

	for (int i = 1; i < argc; i++)
	{
		_original_values.push_back(atoi(argv[i]));
		_vec.push_back(atoi(argv[i]));
		_deq.push_back(atoi(argv[i]));
	}
}

int jacobsthal(int n)
{
	return (pow(2, n) - pow(-1, n)) / 3;
}

//Generate the order in which we transfer from the others to S
std::vector<size_t> generateJacobsthalOrder(size_t n)
{
    std::vector<size_t> indices;
	unsigned int current_jacobsthal;
	unsigned int prev_jacobsthal;
	unsigned int i;

	int k = 3;
	while (true)
	{
		current_jacobsthal = jacobsthal(k);
		if (current_jacobsthal > n + 1)
			break;
		prev_jacobsthal = jacobsthal(k - 1);
		i = current_jacobsthal - prev_jacobsthal;
		while (i > 0)
		{
			indices.push_back(current_jacobsthal);
			current_jacobsthal--;
			i--;
		}
		k++;
	}
	return indices;
}

void PmergeMe::printOriginal() { printContainer(_original_values); }
void PmergeMe::printVector() { printContainer(_vec); }
void PmergeMe::printDeque() { printContainer(_deq); }

void PmergeMe::sortVector() { ford_johnson(_vec, 1); }
void PmergeMe::sortDeque() { ford_johnson(_deq, 1); }