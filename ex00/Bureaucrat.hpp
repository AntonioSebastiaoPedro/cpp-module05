/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:07:19 by ansebast          #+#    #+#             */
/*   Updated: 2025/05/01 23:05:25 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

class Bureaucrat
{
	private:
		std::string name;
		unsigned int grade;
		
		bool isValidGrade( int grade );
	public:
		Bureaucrat( void );
		Bureaucrat( const Bureaucrat& other );
		Bureaucrat( int grade );
		Bureaucrat( std::string name, int grade );
		Bureaucrat& operator=( const Bureaucrat& other );
		~Bureaucrat();

		std::string getName( void ) const;
		unsigned int getGrade( void ) const;
		void addGrade( void );
		void decreaseGrade( void );
		
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<( std::ostream& stream, const Bureaucrat& object );

# endif