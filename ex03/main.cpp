/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:07:31 by ansebast          #+#    #+#             */
/*   Updated: 2025/08/23 18:24:05 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Intern.hpp"

void testHeader(const std::string &title) {
	std::cout << "\n\033[1;34m==== " << title << " ====\033[0m\n";
}

int	main( void )
{
	testHeader("Test: Bureaucrat's grade enough to sign and execute the ShrubberyCreationForm");
	{
		Intern randomIntern;
		Intern testAssign = randomIntern;
		Intern testCopy (testAssign);
		AForm *rrf;

		(void)randomIntern;
		(void)testAssign;
		(void)testCopy;
		(void)rrf;
	}
	
	return (0);
}
