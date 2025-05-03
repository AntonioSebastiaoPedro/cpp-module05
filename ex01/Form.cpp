/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 07:38:51 by ansebast          #+#    #+#             */
/*   Updated: 2025/05/03 19:07:44 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

Form::Form() : name("Form Default"), isSigned(false), signGrade(150), executeGrade(150)
{
	
}

Form::Form( const Form& other )
{
	*this = other;
}

Form::Form(const std::string& name, int signGrade, int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	if ( signGrade > 150 || executeGrade > 150  ){
		throw Form::GradeTooLowException();
	} else if ( signGrade < 1 || executeGrade < 1  ){
		throw Form::GradeTooHighException();
	}
}

Form& Form::operator=( const Form& other )
{
	if (this != &other)
	{
		this->name = other.getName();
		this->isSigned = other.getIsSigned();
		this->signGrade = other.getSignGrade();
		this->executeGrade = other.getExecuteGrade();
	}
	return (*this);
}

Form::~Form()
{
	
}


const std::string& Form::getName( void ) const
{
	return (this->name);
}

unsigned int Form::getSignGrade( void ) const
{
	return (this->signGrade);
}

unsigned int Form::getExecuteGrade( void ) const
{
	return (this->executeGrade);
}

bool Form::getIsSigned( void ) const
{
	return (this->isSigned);
}


void Form::setName( const std::string& name )
{
	this->name = name;
}

void Form::setSignGrade( int grade )
{
	this->signGrade = grade;
}

void Form::setExecuteGrade( int grade )
{
	this->executeGrade = grade;
}

void Form::setIsSigned( bool value )
{
	this->isSigned = value;
}


bool Form::beSigned( const Bureaucrat& bureaucrat )
{
	if (bureaucrat.getGrade() > 150){
		throw Form::GradeTooLowException();
	}
	if (bureaucrat.getGrade() <= this->signGrade){
		this->isSigned = true;
		return (true);
	}
	return (false);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Value too high for the form grade. Maximum allowed value is 1";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Value too low for the form grade. Minimum allowed value is 150";
}

std::ostream& operator<<( std::ostream& stream, const Form& form )
{
	stream << "\nForm Details: "
		<< "\nName: " << form.getName()
		<< "\nIs Sign: " << form.getIsSigned()
		<< "\nSign Grade: " << form.getSignGrade()
		<< "\nExecute Grade: " << form.getExecuteGrade()
		<< std::endl;
	return (stream);
}