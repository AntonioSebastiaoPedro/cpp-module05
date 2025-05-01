/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:07:31 by ansebast          #+#    #+#             */
/*   Updated: 2025/05/01 23:38:51 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include <iostream>

int	main( void )
{
	try {
		Bureaucrat ansebast;
		Bureaucrat pedro("Pedro", 25);
		Bureaucrat other("Solaris", 150);
		
		std::cout << ansebast << std::endl;
		std::cout << pedro << std::endl;
		std::cout << other << std::endl;
		std::cout << std::endl;
		other.addGrade();
		std::cout << other << std::endl;
		pedro.decreaseGrade();
		std::cout << pedro << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	return (0);
}
