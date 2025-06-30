/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:37:45 by gross             #+#    #+#             */
/*   Updated: 2025/06/30 14:24:30 by gross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
	std::srand(static_cast<unsigned int>(time(0)));
	std::cout << "* identify(Base*) test *\n";
	Base base;
	A a;
	B b;
	C c;
	identify(&base);
	identify(&a);
	identify(&b);
	identify(&c);

	std::cout << "\n* identify(Base&) test *\n";
	Base& base1 = base;
	A& a1 = a;
	B& b1 = b;
	C& c1 = c;
	identify(base1);
	identify(a1);
	identify(b1);
	identify(c1);

	std::cout << "* generate() test *\n";
	Base* p = generate();
	if (!p)
		return (1);
	identify(p);
	delete p;
	return (0);
}