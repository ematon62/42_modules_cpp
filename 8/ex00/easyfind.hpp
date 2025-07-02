/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 22:37:13 by gross             #+#    #+#             */
/*   Updated: 2025/07/02 18:09:31 by gross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include <algorithm>
#include <exception>

template<typename T>
bool easyfind(T& c, int n)
{
	return (c.end() != std::find(c.begin(), c.end(), n));
}

#endif