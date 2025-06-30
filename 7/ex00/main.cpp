/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gross <gross@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:37:45 by gross             #+#    #+#             */
/*   Updated: 2025/06/30 15:19:52 by gross            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "template.hpp"

class Data
{
	private:
		std::string _name;
	public:
 		Data(const std::string& name) : _name(name) {};
		~Data() {};
		std::string getName() const { return _name; };
};

int main(void)
{
	std::cout << " * swap() * \n";
	{
		Data a("First");
		Data b("Second");
		Data* pa = &a;
		Data* pb = &b;
		std::cout << pa->getName() << std::endl;
		std::cout << pb->getName() << std::endl;
		swap(pa, pb);
		std::cout << pa->getName() << std::endl;
		std::cout << pb->getName() << std::endl;
	
		int c = 1;
		int d = 2;
		std::cout << c << std::endl;
		std::cout << d << std::endl;
		swap(c, d);
		std::cout << c << std::endl;
		std::cout << d << std::endl;
	}
	
	std::cout << "\n * min() * \n";
	{
		Data a("First");
		Data b("Second");
		Data* pa = &a;
		Data* pb = &b;
		std::cout << pa << std::endl;
		std::cout << pb << std::endl;
		std::cout << min(pa, pb) << std::endl;
		std::cout << min(a.getName(), b.getName()) << std::endl;
	
		int c = 1;
		int d = 2;
		std::cout << c << std::endl;
		std::cout << d << std::endl;
		std::cout << min(c, d) << std::endl;
	}

	std::cout << "\n * max() * \n";
	{
		Data a("First");
		Data b("Second");
		Data* pa = &a;
		Data* pb = &b;
		std::cout << pa << std::endl;
		std::cout << pb << std::endl;
		std::cout << ::max(pa, pb) << std::endl;
		std::cout << max(a.getName(), b.getName()) << std::endl;
	
		int c = 1;
		int d = 2;
		std::cout << c << std::endl;
		std::cout << d << std::endl;
		std::cout << max(c, d) << std::endl;
	}

	std::cout << std::endl;
	{
		int a = 2;
		int b = 3;

		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";
		
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
}