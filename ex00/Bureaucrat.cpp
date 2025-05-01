/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:07:16 by ansebast          #+#    #+#             */
/*   Updated: 2025/05/01 23:03:23 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void )
{
	this->name = "Ansebast";
	this->grade = 150;
}

Bureaucrat::Bureaucrat( std::string name, int grade )
{
	if ( !Bureaucrat::isValidGrade(grade) )
		return ;
	this->grade = grade;
	this->name = name;
}

Bureaucrat::Bureaucrat( int grade )
{
	if ( !Bureaucrat::isValidGrade(grade) )
		return ;
	this->grade = grade;
	this->name = "Ansebast";
}

Bureaucrat::Bureaucrat( const Bureaucrat& other )
{
	*this = other;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other )
{
	if ( this != &other )
	{
		this->name = other.getName();
		this->grade = other.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called\n";
}

std::string Bureaucrat::getName( void ) const
{
	return (this->name);
}

unsigned int Bureaucrat::getGrade( void ) const
{
	return (this->grade);
}

void Bureaucrat::addGrade( void )
{
	if ( !Bureaucrat::isValidGrade(grade) )
		return ;
	this->grade--;
}

void Bureaucrat::decreaseGrade( void )
{
	if ( !Bureaucrat::isValidGrade(grade) )
		return ;
	this->grade++;
}

std::ostream& operator<<( std::ostream& stream, const Bureaucrat& object )
{
	stream << object.getName() << ", bureaucrat grade " << object.getGrade() << ".";
	return (stream);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Value too high for the grade. Maximum allowed value is 1";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Value too low for the grade. Minimum allowed value is 150";
}

//====================UTILS===================
bool Bureaucrat::isValidGrade( int grade )
{
	if ( grade > 150  ){
		throw Bureaucrat::GradeTooLowException();
		return (false);
	} else if ( grade < 1 ){
		throw Bureaucrat::GradeTooHighException();
		return (false);
	}
	return (true);
}