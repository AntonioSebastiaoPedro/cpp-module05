/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 07:38:45 by ansebast          #+#    #+#             */
/*   Updated: 2025/05/02 12:03:07 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <stdexcept>

class  Bureaucrat;
class Form
{
	private:
		std::string name;
		bool isSigned;
		unsigned int signGrade;
		unsigned int executeGrade;
	public:
		Form();
		Form( const Form& other );
		Form(const std::string& name, int signGrade, int executeGrade);
		Form& operator=( const Form& other );
		~Form();

		std::string& getName( void ) const;
		unsigned int getSignGrade( void ) const;
		unsigned int getExecuteGrade( void ) const;
		bool getIsSigned( void ) const;
		
		
		void setName( const std::string& name );
		void setSignGrade( int grade );
		void setExecuteGrade( int grade );
		bool setIsSigned( void ) const;
		
		void beSigned( const Bureaucrat& bureaucrat );

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

std::ostream& operator<<( const std::ostream& stream, const Form& form);

# endif