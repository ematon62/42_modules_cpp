/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:01:39 by gross             #+#    #+#             */
/*   Updated: 2025/09/06 20:13:34 by gross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_MERGE_ME_HPP
#define P_MERGE_ME_HPP

#include <deque>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#define JACOB_OFFSET 2

#define DEBUG_SWAPS 0
#define DEBUG_FILL 0
#define DEBUG_ORDER 0
#define DEBUG_BINARY 0
#define DEBUG_TEMP 0
#define DEBUG_END 0

class PmergeMe
{
	private:
		PmergeMe(PmergeMe& other);
		PmergeMe& operator=(PmergeMe& other);

		std::vector<int> _original_values;
		std::vector<int> _vec;
		std::deque<int> _deq;
		
		public:
			PmergeMe();
			~PmergeMe();
			
			void printOriginal();
			void printVector();
			void printDeque();
			
			void saveOriginalInput(int argc, char **argv);
			
			void sortVector();
			void sortDeque();
};

int jacobsthal(int n);
std::vector<size_t> generateJacobsthalOrder(size_t n);

template<typename T>
bool isSorted(T& container)
{
	int n = container.size();
	for (int i = 0; i < n - 1; i++)
	{
		if (container[i] > container[i + 1])
			return false;
	}
	return true;
}

template<typename T>
void printContainer(T& container)
{
	typename T::iterator it = container.begin();
	typename T::iterator end = container.end();
	for (; it != end; it++)
	{
		std::cout << *it << " ";
	}
}

template<typename T>
T nextElem(T it, int steps)
{
    std::advance(it, steps);
    return it;
}

template<typename T>
void swapPair(T it, int level)
{
    T start = nextElem(it, 1 - level);
    T end = nextElem(start, level);
    while (start != end)
    {
		std::iter_swap(start, nextElem(start, level));
        start++;
    }
}

template<typename T>
void makeAndSwapPairs(T& container, int level, int nb_elems)
{
	typedef typename T::iterator iter;

    iter start = container.begin();
	iter end = nextElem(container.begin(), (nb_elems - (nb_elems % 2 == 1)) * level); //Omit odd elements

    for (iter it = start; it != end; std::advance(it, level * 2))
    {
        iter this_pair = nextElem(it, level - 1);
        iter next_pair = nextElem(it, level * 2 - 1);
        if (*next_pair < *this_pair)
            swapPair(this_pair, level);
    }
}

template<typename T>
void fillSAndOther(T& container, int level, int nb_elems, std::vector<typename T::iterator> &S, std::vector<typename T::iterator> &others)
{
	typedef typename T::iterator iter;
	
	//If we insert the smallest element of the first pair, S will still be sorted
	S.insert(S.end(), nextElem(container.begin(), level - 1));
	S.insert(S.end(), nextElem(container.begin(), level * 2 - 1));
	
	for (int i = 4; i <= nb_elems ; i += 2)
	{
		others.insert(others.end(), nextElem(container.begin(), level * (i - 1) - 1));
		S.insert(S.end(), nextElem(container.begin(), level * i - 1));
	}
	
	//Odd element (= last one) inserted in others
	if (nb_elems % 2 == 1)
	{
		iter odd_elem = nextElem(container.begin(), level * (nb_elems) - 1);
		others.insert(others.end(), odd_elem);
	}
}

//Binary insert while considering that
//if inserting b_i, we look at the [b1, a1..., a_i-1] portion of the main
template<typename T>
void binaryInsert(T& container, std::vector<typename T::iterator> &dest, typename T::iterator elem)
{
	(void)container;

    size_t left = 0;
    size_t right = dest.size();

    while (left < right) {
        std::size_t mid = left + (right - left) / 2;
        if (*dest[mid] < *elem)
            left = mid + 1;
        else
            right = mid;
    }

    dest.insert(dest.begin() + left, elem);
}

template<typename T>
void putBackIntoContainer(T& container, std::vector<typename T::iterator>& S, int level)
{
	std::vector<int> temp;
	typedef typename T::iterator iter;

	iter S_elem;
	for (typename std::vector<iter>::iterator it = S.begin(); it != S.end(); it++)
    {
		for (int i = 0; i < level; i++)
        {
			S_elem = *it;
			std::advance(S_elem, -level + i + 1);
			temp.insert(temp.end(), *S_elem);
        }
	}

	int m = 0;
	for (std::vector<int>::iterator it = temp.begin(); it != temp.end(); it++)
	{
		container[m] = *it;
		m++;
	}
}

//Level of recursion is a power of 2
template<typename T>
void ford_johnson(T& container, int level)
{
	typedef typename T::iterator iter;
	std::vector<iter> S; //Biggest element of each pair
	std::vector<iter> others; //Smallest element of each pair
	
	//Simple case: not enough elements to create at least a pair
	int nb_elems = container.size() / level;
    if (static_cast<int>(nb_elems) < 2)
		return ;
	
	//Recursively swap pairs of pairs...
    makeAndSwapPairs(container, level, nb_elems);
    ford_johnson(container, level * 2);

	fillSAndOther(container, level, nb_elems, S, others);
	std::cout << "LEVEL: " << level << std::endl;
	for (typename std::vector<iter>::iterator it = S.begin(); it != S.end(); it++)
		std::cout << *(*it) << " ";
	std::cout << std::endl;
	for (typename std::vector<iter>::iterator it = others.begin(); it != others.end(); it++)
		std::cout << *(*it) << " ";
	std::cout << std::endl;

	//Get order in which we insert
	std::vector<size_t> insertion_order = generateJacobsthalOrder(others.size());

	//Binary Insert elements from the pend to the main according to Jacobsthal order
	unsigned int i = 0;
	for (; i < insertion_order.size(); i++)
		binaryInsert(container, S, others[insertion_order[i] - JACOB_OFFSET]);

	//Insert remaining elements in reverse order
	typename std::vector<iter>::iterator ot = nextElem(others.begin(), insertion_order.size());
	while (ot != others.end())
	{
		binaryInsert(container, S, *ot);
		ot++;
	}

	
	// Go from heads of pairs to full pairs in main container
	// With temporary container
	putBackIntoContainer(container, S, level);
}

#endif