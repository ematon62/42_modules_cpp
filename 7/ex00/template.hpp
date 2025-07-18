/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:42:51 by gross             #+#    #+#             */
/*   Updated: 2025/06/30 15:19:59 by gross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <iostream>

template<typename T>
void swap(T& a, T& b)
{
	T c = a;
	a = b;
	b = c;
}

template<typename T>
T& min(T& a, T& b)
{
	return (a < b ? a : b);	
}

template<typename T>
T& max(T& a, T& b)
{
	return (a < b ? b : a);
}

#endif