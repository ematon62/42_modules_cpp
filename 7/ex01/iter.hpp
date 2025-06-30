/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:42:51 by gross             #+#    #+#             */
/*   Updated: 2025/06/30 16:54:58 by gross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <iostream>

template<typename T>
void print(T& x)
{
    std::cout << x << std::endl;
}

template<typename T>
void print2(const T& x)
{
    std::cout << x << std::endl;
}

template<typename T>
void iter(T array[], size_t n, void (*f)(const T& x))
{
    for (size_t i = 0; i < n; i++)
    {
        f(array[i]);
    }
}

#endif