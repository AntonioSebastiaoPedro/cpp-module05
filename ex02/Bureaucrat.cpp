/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:07:16 by ansebast          #+#    #+#             */
/*   Updated: 2025/08/23 12:58:18 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : name("Ansebast"), grade(150)
{
}

Bureaucrat::Bureaucrat( const std::string& name, int grade ): name(name), grade(grade)
{
	if ( grade > 150  ){
		throw Bureaucrat::GradeTooLowException();
	} else if ( grade < 1 ){
		throw Bureaucrat::GradeTooHighException();
	}
}

Bureaucrat::Bureaucrat( int grade ): name("Ansebast"), grade(grade)
{
	if ( grade > 150  ){
		throw Bureaucrat::GradeTooLowException();
	} else if ( grade < 1 ){
		throw Bureaucrat::GradeTooHighException();
	}
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
}

const std::string& Bureaucrat::getName( void ) const
{
	return (this->name);
}

unsigned int Bureaucrat::getGrade( void ) const
{
	return (this->grade);
}

void Bureaucrat::setName( const std::string& name )
{
	this->name = name;
}

void Bureaucrat::setGrade( int grade )
{
	if ( grade > 150  ){
		throw Bureaucrat::GradeTooLowException();
	} else if ( grade < 1 ){
		throw Bureaucrat::GradeTooHighException();
	}
	this->grade = grade;
}


void Bureaucrat::addGrade( void )
{
	if ( grade == 1 )
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
	std::cout << this->name << "\'s grade incremented\n";
}

void Bureaucrat::decreaseGrade( void )
{
	if ( grade == 150 )
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
	std::cout << this->name << "\'s grade decremented\n";
}

void Bureaucrat::signForm( AForm& form )
{
	if ( form.getIsSigned() ) {
		return ;
	}
	if ( form.beSigned(*this) ){
		std::cout << this->name
			<< " signed "
			<< form.getName()
			<< std::endl;
	} else {
		std::cout << this->name
		<< " couldn't sign "
		<< form.getName()
		<< " because the required grade is "
		<< form.getSignGrade()
		<< " and the " << this->name << "'s grade is "
		<< this->grade
		<< std::endl;
	}
}

std::ostream& operator<<( std::ostream& stream, const Bureaucrat& object )
{
	stream << object.getName() << ", bureaucrat grade " << object.getGrade() << ".";
	return (stream);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Value too high for the bureaucrat grade. Maximum allowed value is 1";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Value too low for the bureaucrat grade. Minimum allowed value is 150";
}

void Bureaucrat::executeForm(AForm const & form) const
{
	if (!form.execute(*this)) {
		std::cout << "Form " << form.getName() << " cannot be executed" << std::endl;
		return ;
	}
	std::cout << this->getName() << " executed " << form.getName() << std::endl;
}