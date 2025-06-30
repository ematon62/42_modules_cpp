/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:24:12 by gross             #+#    #+#             */
/*   Updated: 2025/06/30 14:07:10 by gross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSES_HPP
#define CLASSES_HPP

#include <iostream>
#include <cstdlib>

enum derived_type { IS_A, IS_B, IS_C };

class Base { public: virtual ~Base() {} };

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base* generate(void);

void identify(Base* p);

void identify(Base& p);

#endif 