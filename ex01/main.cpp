/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:07:31 by ansebast          #+#    #+#             */
/*   Updated: 2025/05/03 19:54:05 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include <iostream>

void testHeader(const std::string &title) {
	std::cout << "\n\033[1;34m==== " << title << " ====\033[0m\n";
}

int	main( void )
{
	testHeader("Teste 1: Bureaucrat's grade enough to sign the form");
	{
		try {
			Bureaucrat ansebast(42);
			Form leaveRequest("Leave Request", 100, 50);
			ansebast.signForm(leaveRequest);
			std::cout << leaveRequest << std::endl;
		} catch (const std::exception &e) {
			std::cerr << "\033[1;31m" << "Error: " << "\033[0m" << e.what() << std::endl;
		}
	}
	
	testHeader("Teste 2: Bureaucrat's grade not enough to sign the form");
	{
		try {
			Bureaucrat alice("Alice", 120);
			Form budget("Budget Approval", 100, 50);
			alice.signForm(budget);
			std::cout << budget << std::endl;
		} catch (const std::exception &e) {
			std::cerr << "\033[1;31m" << "Caught: " << "\033[0m" << e.what() << std::endl;
		}
	}
	
	testHeader("Teste 3: Traying to sign the same form twice");
	{
		try {
			Bureaucrat john("John", 10);
			Form promotion("Promotion Form", 50, 25);
			john.signForm(promotion);
			john.signForm(promotion);
			std::cout << promotion << std::endl;
		} catch (const std::exception &e) {
			std::cerr << "\033[1;31m" << "Caught: " << "\033[0m" << e.what() << std::endl;
		}
	}
	
	testHeader("Teste 4: Bureaucrat's grade iqual to the form's grade");
	{
		try {
			Bureaucrat ana("Ana", 50);
			Form mission("Mission Order", 50, 20);
			ana.signForm(mission);
			std::cout << mission << std::endl;
		} catch (const std::exception &e) {
			std::cerr << "\033[1;31m" << "Caught: " << "\033[0m" << e.what() << std::endl;
		}
	}
	
	testHeader("Teste 5: Bureaucrat's grade one point lower than required");
	{
		try {
			Bureaucrat carl("Carl", 51);
			Form mission("Mission Order", 50, 20);
			carl.signForm(mission);
			std::cout << mission << std::endl;
		} catch (const std::exception &e) {
			std::cerr << "\033[1;31m" << "Caught: " << "\033[0m" << e.what() << std::endl;
		}
	}

	testHeader("Teste 6: Bureaucrat's grade one point greater than required");
	{
		try {
			Bureaucrat pedro("Pedro", 17);
			Form mission("Mission Order", 18, 1);
			pedro.signForm(mission);
			std::cout << mission << std::endl;
		} catch (const std::exception &e) {
			std::cerr << "\033[1;31m" << "Error: " << "\033[0m" << e.what() << std::endl;
		}
	}
	
	testHeader("Teste 7: Bureaucrat's grade enough to sign all forms");
	{
		try {
			Bureaucrat director("Director", 1);
			Form topSecret("Top Secret Doc", 1, 1);
			Form minorForm("Minor Request", 150, 150);

			director.signForm(topSecret);
			std::cout << topSecret << std::endl;
			director.signForm(minorForm);
			std::cout << minorForm << std::endl;
		} catch (const std::exception &e) {
			std::cerr << "\033[1;31m" << "Error: " << "\033[0m" << e.what() << std::endl;
		}
	}
	
	testHeader("Teste 8: Invalid values to show exceptions messages");
	{
		try {
			Form f1("Invalid High", 1, 0);
		} catch (const std::exception &e) {
			std::cerr << "\033[1;31m" << "Error: " << "\033[0m" << e.what() << std::endl;
		}

		try {
			Form f2("Invalid Low", 151, 10);
		} catch (const std::exception &e) {
			std::cerr << "\033[1;31m" << "Error: " << "\033[0m" << e.what() << std::endl;
		}
		
		try {
			Bureaucrat b1("Invalid High", 0);
		} catch (const std::exception &e) {
			std::cerr << "\033[1;31m" << "Error: " << "\033[0m" << e.what() << std::endl;
		}

		try {
			Bureaucrat b1("Invalid Low", 151);
		} catch (const std::exception &e) {
			std::cerr << "\033[1;31m" << "Error: " << "\033[0m" << e.what() << std::endl;
		}

		try {
			Bureaucrat b1("Invalid Low", -1);
		} catch (const std::exception &e) {
			std::cerr << "\033[1;31m" << "Error: " << "\033[0m" << e.what() << std::endl;
		}
	}
	return (0);
}
