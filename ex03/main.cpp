/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:07:31 by ansebast          #+#    #+#             */
/*   Updated: 2025/08/27 14:34:06 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Intern.hpp"

void testHeader(const std::string &title) {
	std::cout << "\n\033[1;34m==== " << title << " ====\033[0m\n";
}

int	main( void )
{
	testHeader("Test: Intern creating a ShrubberyCreationForm");
	{
		try
		{
			Bureaucrat ansebast(9);
			Intern someRandomIntern;
			AForm* scf;
			scf = someRandomIntern.makeForm("shrubbery creation", "Home");
			ansebast.signForm(*scf);
			ansebast.executeForm(*scf);
			std::cout << *scf << std::endl;
			delete scf;
		} catch (const std::exception &e) {
			std::cerr << "\033[1;31m" << "Error: " << "\033[0m" << e.what() << std::endl;
		}
	}

	testHeader("Test: Intern creating a RobotomyRequestForm");
	{
		try
		{
			Bureaucrat ansebast(12);
			Intern someRandomIntern;
			AForm* rrf;
			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
			ansebast.executeForm(*rrf);
			std::cout << *rrf << std::endl;
			delete rrf;
		} catch (const std::exception &e) {
			std::cerr << "\033[1;31m" << "Error: " << "\033[0m" << e.what() << std::endl;
		}
	}
	
	testHeader("Test: Intern creating a PresidentialPardonForm");
	{
		AForm* ppf;
		try
		{
			Bureaucrat ansebast(12);
			Intern someRandomIntern;
			ppf = someRandomIntern.makeForm("presidential pardon", "42Luanda House");
			ansebast.signForm(*ppf);
			ansebast.executeForm(*ppf);
		} catch (const std::exception &e) {
			delete ppf;
			std::cerr << "\033[1;31m" << "Error: " << "\033[0m" << e.what() << std::endl;
		}
	}

	testHeader("Test: Form does not exists");
	{
		try
		{
			Intern someRandomIntern;
			AForm* other;
			other = someRandomIntern.makeForm("other form", "Impossible");
			if (other != NULL)
				std::cout << *other << std::endl;
		} catch (const std::exception &e) {
			std::cerr << "\033[1;31m" << "Error: " << "\033[0m" << e.what() << std::endl;
		}
	}

	return (0);
}
