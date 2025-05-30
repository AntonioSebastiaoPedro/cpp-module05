/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 07:38:51 by ansebast          #+#    #+#             */
/*   Updated: 2025/05/30 09:18:06 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

AForm::AForm() : name("Form Default"), isSigned(false), signGrade(150), executeGrade(150)
{
	
}

AForm::AForm( const AForm& other )
{
	*this = other;
}

AForm::AForm(const std::string& name, int signGrade, int executeGrade) : name(name), isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
	if ( signGrade > 150 || executeGrade > 150  ){
		throw AForm::GradeTooLowException();
	} else if ( signGrade < 1 || executeGrade < 1  ){
		throw AForm::GradeTooHighException();
	}
}

AForm& AForm::operator=( const AForm& other )
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

AForm::~AForm()
{
	
}


const std::string& AForm::getName( void ) const
{
	return (this->name);
}

unsigned int AForm::getSignGrade( void ) const
{
	return (this->signGrade);
}

unsigned int AForm::getExecuteGrade( void ) const
{
	return (this->executeGrade);
}

bool AForm::getIsSigned( void ) const
{
	return (this->isSigned);
}


void AForm::setName( const std::string& name )
{
	this->name = name;
}

void AForm::setSignGrade( int grade )
{
	if ( grade > 150 ){
		throw AForm::GradeTooLowException();
	} else if ( grade < 1 ){
		throw AForm::GradeTooHighException();
	}
	this->signGrade = grade;
}

void AForm::setExecuteGrade( int grade )
{
	if ( grade > 150 ){
		throw AForm::GradeTooLowException();
	} else if ( grade < 1 ){
		throw AForm::GradeTooHighException();
	}
	this->executeGrade = grade;
}

void AForm::setIsSigned( bool value )
{
	this->isSigned = value;
}


bool AForm::beSigned( const Bureaucrat& bureaucrat )
{
	if (bureaucrat.getGrade() > 150){
		throw AForm::GradeTooLowException();
	}
	if (bureaucrat.getGrade() <= this->signGrade){
		this->isSigned = true;
		return (true);
	}
	return (false);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Value too high for the form grade. Maximum allowed value is 1";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Form grade is invalid (value > 150) OR Bureaucrat grade is too low for this action.";
}

std::ostream& operator<<( std::ostream& stream, const AForm& form )
{
	stream << "Form Details: [Name: " << form.getName()
		<< ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
		<< ", Grade to Sign: " << form.getSignGrade()
		<< ", Grade to Execute: " << form.getExecuteGrade()
		<< "]";
	return (stream);
}