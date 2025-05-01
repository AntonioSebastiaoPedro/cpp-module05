/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:07:31 by ansebast          #+#    #+#             */
/*   Updated: 2025/05/01 23:09:49 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include <iostream>

int	main( void )
{
	Bureaucrat ansebast;
	Bureaucrat pedro(25);
	Bureaucrat other("Solaris", 7);
	std::cout << ansebast
		<< std::endl;
	std::cout << pedro
		<< std::endl;
	std::cout << other
		<< std::endl;
	
	return (0);
}
