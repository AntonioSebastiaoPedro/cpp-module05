/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:07:19 by ansebast          #+#    #+#             */
/*   Updated: 2025/05/01 21:28:33 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
	private:
		std::string name;
		unsigned int grade;
	public:
		Bureaucrat( void );
		Bureaucrat( const Bureaucrat& other );
		Bureaucrat( std::string name, int grade );
		Bureaucrat& operator=( const Bureaucrat& other );
		~Bureaucrat();

		std::string getName( void ) const;
		unsigned int getGrade( void ) const;
		void addGrade( void );
		void decreaseGrade( void );

		Bureaucrat& operator++( int );
		Bureaucrat& operator++( void );
		Bureaucrat& operator--( int );
		Bureaucrat& operator--( void );
};

# endif