/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:07:31 by ansebast          #+#    #+#             */
/*   Updated: 2025/08/27 13:19:46 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include <iostream>

void testHeader(const std::string &title) {
	std::cout << "\n\033[1;34m==== " << title << " ====\033[0m\n";
}


int	main( void )
{
	testHeader("Test: Testing increment and drecrement grade methods");
	try {
		Bureaucrat ansebast;
		std::cout << ansebast << std::endl;
		std::cout << "Incrementing grade...\n";
		ansebast.addGrade();
		std::cout << ansebast << std::endl;
		std::cout << "Decrementing grade...\n";
		ansebast.decreaseGrade();
		std::cout << ansebast << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << "\033[1;31m" << "Error: " << "\033[0m" << e.what() << std::endl;
	}

	testHeader("Test: Testing getters and setters");
	try {
		Bureaucrat ansebast;
		std::cout << ansebast << std::endl;
		std::cout << "Setting name and grade...\n";
		ansebast.setName("New Name");
		ansebast.setGrade(24);
		std::cout << ansebast << std::endl;
		std::cout << "Getting name and grade...\n";
		std::cout << "Name: " << ansebast.getName() << "\nGrade: " << ansebast.getGrade() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << "\033[1;31m" << "Error: " << "\033[0m" << e.what() << std::endl;
	}

	testHeader("Test: Throw exception on seeting grade");
	try {
		Bureaucrat jany("Jany", 21);
		int grade = 151;
		std::cout << jany << std::endl;
		std::cout << "Setting grade " << grade << "...\n";
		jany.setGrade(grade);
	}
	catch(const std::exception& e) {
		std::cerr << "\033[1;31m" << "Error: " << "\033[0m" << e.what() << std::endl;
	}

	testHeader("Test: Throw exception on incrementing grade");
	try {
		Bureaucrat jany("Jany", 1);
		std::cout << jany << std::endl;
		std::cout << "Incrementing grade...\n";
		jany.addGrade();
		std::cout << jany << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << "\033[1;31m" << "Error: " << "\033[0m" << e.what() << std::endl;
	}

	testHeader("Test: Throw exception on incrementing grade");
	try {
		Bureaucrat ansebast(150);
		std::cout << ansebast << std::endl;
		std::cout << "Decrementing grade...\n";
		ansebast.decreaseGrade();
	}
	catch(const std::exception& e) {
		std::cerr << "\033[1;31m" << "Error: " << "\033[0m" << e.what() << std::endl;
	}
	
	return (0);
}
