/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 07:38:45 by ansebast          #+#    #+#             */
/*   Updated: 2025/08/20 01:32:58 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <stdexcept>

class  Bureaucrat;
class AForm
{
	private:
		std::string name;
		bool isSigned;
		unsigned int signGrade;
		unsigned int executeGrade;
	public:
		AForm();
		AForm( const AForm& other );
		AForm(const std::string& name, int signGrade, int executeGrade);
		AForm& operator=( const AForm& other );
		~AForm();

		const std::string& getName( void ) const;
		unsigned int getSignGrade( void ) const;
		unsigned int getExecuteGrade( void ) const;
		bool getIsSigned( void ) const;
		
		
		void setName( const std::string& name );
		void setSignGrade( int grade );
		void setExecuteGrade( int grade );
		void setIsSigned( bool value );
		
		bool beSigned( const Bureaucrat& bureaucrat );
		virtual void execute(Bureaucrat const & executor) const = 0;

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

std::ostream& operator<<( std::ostream& stream, const AForm& form);

# endif