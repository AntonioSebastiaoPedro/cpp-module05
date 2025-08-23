/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:07:31 by ansebast          #+#    #+#             */
/*   Updated: 2025/08/23 12:53:14 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <iostream>

void testHeader(const std::string &title) {
	std::cout << "\n\033[1;34m==== " << title << " ====\033[0m\n";
}

int	main( void )
{
	testHeader("Test: Bureaucrat's grade enough to sign and execute the ShrubberyCreationForm");
	{
		try {
			Bureaucrat ansebast(42);
			ShrubberyCreationForm form1("home");
			std::cout << "Bureaucrat's details: " << ansebast << std::endl;
			std::cout << "Form before sign: " << form1 << std::endl;
			ansebast.signForm(form1);
			std::cout << "Form after sign: " << form1 << std::endl;
			ansebast.executeForm(form1);
		} catch (const std::exception &e) {
			std::cerr << "\033[1;31m" << "Error: " << "\033[0m" << e.what() << std::endl;
		}
	}
	
	testHeader("Test: Bureaucrat trying to execute ShrubberyCreationForm that is not signed");
	{
		try
		{
			Bureaucrat ansebast(10);
			std::cout << "Bureaucrat's details: " << ansebast << std::endl;
			ShrubberyCreationForm form1("office");
			std::cout << "Form defore execution: " << form1 << std::endl;
			ansebast.executeForm(form1);
			std::cout << "Form after execution: " << form1 << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "\033[1;31m" << "Error: " << "\033[0m" << e.what() << std::endl;
		}
	}
	
	testHeader("Test: Bureaucrat executing a RobotomyRequestForm");
	{
		try
		{
			Bureaucrat ansebast(10);
			std::cout << "Bureaucrat's details: " << ansebast << std::endl;
			RobotomyRequestForm f1("bootcamp");
			std::cout << "Form before sign: " << f1 << std::endl;
			ansebast.signForm(f1);
			std::cout << "Form after sign: " << f1 << std::endl;
			ansebast.executeForm(f1);
		}
		catch(const std::exception& e)
		{
			std::cerr << "\033[1;31m" << "Error: " << "\033[0m" << e.what() << std::endl;
		}
		
	}

	testHeader("Test: Bureaucrat's grade is not enough to execute the PresidentialPardonForm");
	{
		try
		{
			Bureaucrat ansebast(10);
			std::cout << "Bureaucrat's details: " << ansebast << std::endl;
			PresidentialPardonForm f1("cheat");
			std::cout << "Form before sign: " << f1 << std::endl;
			ansebast.signForm(f1);
			std::cout << "Form after sign: " << f1 << std::endl;
			ansebast.executeForm(f1);
		}
		catch(const std::exception& e)
		{
			std::cerr << "\033[1;31m" << "Error: " << "\033[0m" << e.what() << std::endl;
		}
		
	}

	testHeader("Test: Bureaucrat executing a PresidentialPardonForm");
	{
		try
		{
			Bureaucrat ansebast(5);
			std::cout << "Bureaucrat's details: " << ansebast << std::endl;
			PresidentialPardonForm f1("cheat");
			std::cout << "Form before sign: " << f1 << std::endl;
			ansebast.signForm(f1);
			std::cout << "Form after sign: " << f1 << std::endl;
			ansebast.executeForm(f1);
		}
		catch(const std::exception& e)
		{
			std::cerr << "\033[1;31m" << "Error: " << "\033[0m" << e.what() << std::endl;
		}
		
	}
	return (0);
}
