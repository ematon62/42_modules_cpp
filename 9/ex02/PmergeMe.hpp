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
	//If we insert the smallest element of the first pair, S will still be sorted
	S.insert(S.begin(), nextElem(container.begin(), level - 1));
	S.insert(S.end(), nextElem(container.begin(), level * 2 - 1));
	
	for (int i = 4; i <= nb_elems ; i += 2)
	{
		others.insert(others.end(), nextElem(container.begin(), level * (i - 1) - 1));
		S.insert(S.end(), nextElem(container.begin(), level * i - 1));
	}

	//Odd element inserted in others
	if (nb_elems % 2 == 1)
		others.insert(others.end(), nextElem(container.end(), - (level - 1)));
}

template<typename T>
void binaryInsert(T& container, std::vector<typename T::iterator> &src, std::vector<typename T::iterator> &dest, unsigned int index)
{
	(void)container;
	typedef typename T::iterator iter;
	if (index >= src.size()) return; // invalid index

    iter elem = src[index];
    size_t left = 0;
    size_t right = dest.size();

    while (left < right) {
        std::size_t mid = left + (right - left) / 2;
        if (*dest[mid] < *elem)
            left = mid + 1;
        else
            right = mid;
    }

    // Insert at the found position
    dest.insert(dest.begin() + left, elem);
}

//Level of recursion is a power of 2
template<typename T>
void ford_johnson(T& container, int level)
{
	typedef typename T::iterator iter;
	
	std::vector<iter> S; //Biggest element of each pair
	std::vector<iter> others; //Smallest element of each pair
	std::vector<int> copy; //To put back pairs into main
	
	//Simple case: not enough elements to create at least a pair
	int nb_elems = container.size() / level;
    if (static_cast<int>(nb_elems) < 2)
        return ;

    makeAndSwapPairs(container, level, nb_elems);
    ford_johnson(container, level * 2);

	fillSAndOther(container, level, nb_elems, S, others);

	std::vector<size_t> insertion_order = generateJacobsthalOrder(others.size()); //Order in which we insert

	//Binary Insert elements from the pend to the main according to Jacobsthal order
	unsigned int i = 0;
	for (; i < insertion_order.size(); i++)
		binaryInsert(container, others, S, i - JACOB_OFFSET);

	//Insert remaining elements in pend in reverse order
	int j = static_cast<int>(i);
	for (int k = static_cast<int>(others.size()) - 1; k >= j; k--)
		binaryInsert(container, others, S, k);

	//Go from heads of pairs to full pairs in main container
}
#endif