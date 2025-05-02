/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:07:31 by ansebast          #+#    #+#             */
/*   Updated: 2025/05/02 06:54:10 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include <iostream>

int	main( void )
{
	try {
		Bureaucrat ansebast;
		Bureaucrat pedro("Pedro", 25);
		Bureaucrat other(pedro);
		Bureaucrat invalid = ansebast;
		
		ansebast.setGrade(17);
		other.setName("Other");
		other.setGrade(1);
		invalid.setName("Invalid");

		std::cout << ansebast << std::endl;
		std::cout << pedro << std::endl;
		std::cout << other << std::endl;
		std::cout << invalid << std::endl;
		std::cout << std::endl;
		other.decreaseGrade();
		std::cout << other << std::endl;
		invalid.addGrade();
		std::cout << invalid << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return (0);
}
