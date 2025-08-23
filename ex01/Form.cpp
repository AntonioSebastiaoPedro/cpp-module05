/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 07:38:51 by ansebast          #+#    #+#             */
/*   Updated: 2025/08/23 12:40:17 by ansebast         ###   ########.fr       */
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
	if ( grade > 150 ){
		throw Form::GradeTooLowException();
	} else if ( grade < 1 ){
		throw Form::GradeTooHighException();
	}
	this->signGrade = grade;
}

void Form::setExecuteGrade( int grade )
{
	if ( grade > 150 ){
		throw Form::GradeTooLowException();
	} else if ( grade < 1 ){
		throw Form::GradeTooHighException();
	}
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
	return "Form grade is invalid (value > 150 or value < 1) OR Bureaucrat grade is too low for this action.";
}

std::ostream& operator<<( std::ostream& stream, const Form& form )
{
	stream << "Form: [Name: " << form.getName()
		<< ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
		<< ", Grade to Sign: " << form.getSignGrade()
		<< ", Grade to Execute: " << form.getExecuteGrade()
		<< "]";
	return (stream);
}