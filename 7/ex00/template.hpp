/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:42:51 by gross             #+#    #+#             */
/*   Updated: 2025/06/30 15:01:41 by gross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <iostream>

template<typename T>
void swap(T& a, T& b);

template<typename T>
T& min(T& a, T& b);

template<typename T>
T& max(T& a, T& b);

#endif