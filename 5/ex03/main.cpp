/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ematon <ematon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:16:49 by ematon            #+#    #+#             */
/*   Updated: 2025/06/17 15:28:21 by ematon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern someRandomIntern;

	try
	{
		someRandomIntern.makeForm("existe po", "oui-oui");
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	std::cout << "\033[1;32mShrubbery Creation Form\033[0m\n";
	{
		AForm* f;
		try
		{
			f = someRandomIntern.makeForm("shrubbery creation form", "jp");
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << '\n';
			exit(1);
		}
		std::cout << *f;
		f->printTarget();
		Bureaucrat gorille(146, "fail sign");
		Bureaucrat gorille2(144, "success sign");
		Bureaucrat gorille3(135, "exec_n_sign");
		
		std::cout << "\n\033[1;31mUnsuccessful execForm due to not signed\033[0m\n";
		std::cout << gorille;
		std::cout << "Trying execute...\n";
		gorille.executeForm(*f);

		std::cout << "\033[1;31mUnsuccesful beSigned\033[0m\n";
		std::cout << gorille;
		try
		{
			std::cout << "Trying beSigned...\n";
			f->beSigned(gorille);
			std::cout << *f;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << "\033[1;31mSuccesful beSigned\033[0m\n";
		std::cout << gorille2;
		try
		{
			std::cout << "Trying beSigned...\n";
			f->beSigned(gorille2);
			std::cout << *f;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		std::cout << "\n\033[1;31mUnsuccessful execute\033[0m\n";
		std::cout << gorille;
		try
		{
			std::cout << "Trying execute...\n";
			f->execute(gorille);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << "\033[1;31mSuccessful execute\033[0m\n";
		std::cout << gorille3;
		try
		{
			std::cout << "Trying execute...\n";
			f->execute(gorille3);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << "\n\033[1;31mUnsuccessful execForm due to grade\033[0m\n";
		std::cout << gorille;
		std::cout << "Trying execute...\n";
		gorille.executeForm(*f);

		std::cout << "\033[1;31mSuccessful execute\033[0m\n";
		std::cout << gorille3;
		std::cout << "Trying execute...\n";
		try
		{
			gorille3.executeForm(*f);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		delete f;
	}

	std::cout << "\n\033[1;32mRobotomy Request Form\033[0m\n";
	{
		AForm* f;
		try
		{
			f = someRandomIntern.makeForm("robotomy request form", "jp");
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << '\n';
			exit(1);
		}
		std::cout << *f;
		f->printTarget();
		Bureaucrat gorille(73, "fail sign");
		Bureaucrat gorille2(46, "success sign");
		Bureaucrat gorille3(44, "exec_n_sign");
		
		std::cout << "\n\033[1;31mUnsuccessful execForm due to not signed\033[0m\n";
		std::cout << gorille;
		std::cout << "Trying execute...\n";
		gorille.executeForm(*f);

		std::cout << "\033[1;31mUnsuccesful beSigned\033[0m\n";
		std::cout << gorille;
		try
		{
			std::cout << "Trying beSigned...\n";
			f->beSigned(gorille);
			std::cout << *f;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << "\033[1;31mSuccesful beSigned\033[0m\n";
		std::cout << gorille2;
		try
		{
			std::cout << "Trying beSigned...\n";
			f->beSigned(gorille2);
			std::cout << *f;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		std::cout << "\n\033[1;31mUnsuccessful execute\033[0m\n";
		std::cout << gorille;
		try
		{
			std::cout << "Trying execute...\n";
			f->execute(gorille);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << "\033[1;31mSuccessful execute\033[0m\n";
		std::cout << gorille3;
		try
		{
			std::cout << "Trying execute...\n";
			f->execute(gorille3);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << "\n\033[1;31mUnsuccessful execForm due to grade\033[0m\n";
		std::cout << gorille;
		std::cout << "Trying execute...\n";
		gorille.executeForm(*f);

		std::cout << "\033[1;31mSuccessful execForm\033[0m\n";
		std::cout << gorille3;
		std::cout << "Trying execute...\n";
		gorille3.executeForm(*f);
		delete f;
	}

	std::cout << "\n\033[1;32mPresidential Pardon Form\033[0m\n";
	{
		AForm* f;
		try
		{
			f = someRandomIntern.makeForm("presidential pardon form", "jp");
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << '\n';
			exit(1);
		}
		std::cout << *f;
		f->printTarget();
		Bureaucrat gorille(26, "fail sign");
		Bureaucrat gorille2(25, "success sign");
		Bureaucrat gorille3(5, "exec_n_sign");
		
		std::cout << "\n\033[1;31mUnsuccessful execForm due to not signed\033[0m\n";
		std::cout << gorille;
		std::cout << "Trying execute...\n";
		gorille.executeForm(*f);

		std::cout << "\033[1;31mUnsuccesful beSigned\033[0m\n";
		std::cout << gorille;
		try
		{
			std::cout << "Trying beSigned...\n";
			f->beSigned(gorille);
			std::cout << *f;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << "\033[1;31mSuccesful beSigned\033[0m\n";
		std::cout << gorille2;
		try
		{
			std::cout << "Trying beSigned...\n";
			f->beSigned(gorille2);
			std::cout << *f;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		std::cout << "\n\033[1;31mUnsuccessful execute\033[0m\n";
		std::cout << gorille;
		try
		{
			std::cout << "Trying execute...\n";
			f->execute(gorille);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << "\033[1;31mSuccessful execute\033[0m\n";
		std::cout << gorille3;
		try
		{
			std::cout << "Trying execute...\n";
			f->execute(gorille3);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << "\n\033[1;31mUnsuccessful execForm due to grade\033[0m\n";
		std::cout << gorille;
		std::cout << "Trying execute...\n";
		gorille.executeForm(*f);

		std::cout << "\033[1;31mSuccessful execForm\033[0m\n";
		std::cout << gorille3;
		std::cout << "Trying execute...\n";
		gorille3.executeForm(*f);
		delete f;
	}
}