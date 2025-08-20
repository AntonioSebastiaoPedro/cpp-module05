/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:07:31 by ansebast          #+#    #+#             */
/*   Updated: 2025/08/20 02:30:03 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include <iostream>

void testHeader(const std::string &title) {
	std::cout << "\n\033[1;34m==== " << title << " ====\033[0m\n";
}

int	main( void )
{
	testHeader("Test 1: Bureaucrat's grade enough to sign and execute the ShrubberyCreationForm");
	{
		try {
			Bureaucrat ansebast(42);
			ShrubberyCreationForm form1("home");
			ansebast.signForm(form1);
			form1.execute(ansebast);
			std::cout << form1 << std::endl;
		} catch (const std::exception &e) {
			std::cerr << "\033[1;31m" << "Error: " << "\033[0m" << e.what() << std::endl;
		}
	}
	
	testHeader("Test 2: Bureaucrats trying to execute ShrubberyCreationForm that is not signed");
	{
		try
		{
			Bureaucrat ansebast(10);
			ShrubberyCreationForm form1("office");
			form1.execute(ansebast);
			std::cout << form1 << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "\033[1;31m" << "Error: " << "\033[0m" << e.what() << std::endl;
		}
	}
	
	return (0);
}
