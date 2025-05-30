/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 09:24:16 by ansebast          #+#    #+#             */
/*   Updated: 2025/05/30 09:37:00 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Form Default", 145, 137)
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other ) : AForm(other)
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name, int signGrade, int executeGrade) : AForm(name, 145, 137)
{
	if ( signGrade > 150 || executeGrade > 150  ){
		throw ShrubberyCreationForm::GradeTooLowException();
	} else if ( signGrade < 1 || executeGrade < 1  ){
		throw ShrubberyCreationForm::GradeTooHighException();
	}
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other )
{
	if (this != &other)
	{
		this->setName(other.getName());
		this->setIsSigned(other.getIsSigned());
		this->setSignGrade(other.getSignGrade());
		this->setExecuteGrade(other.getExecuteGrade());
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}