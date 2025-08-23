/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 09:24:16 by ansebast          #+#    #+#             */
/*   Updated: 2025/08/20 02:25:18 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"
# include <fstream>
# include <stdlib.h>
# include <ctime>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm Default", 25, 5)
{
	
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& name) : AForm(name, 25, 5)
{
	
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& other ) : AForm(other)
{
	this->setSignGrade(25);
	this->setExecuteGrade(5);
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& other )
{
	if (this != &other)
	{
		this->setName(other.getName());
		this->setIsSigned(other.getIsSigned());
		this->setSignGrade(25);
		this->setExecuteGrade(5);
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	
}

bool PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned()) {
		std::cout << this->getName() << " PresidentialPardonForm is not signed yet" << std::endl;
		return false;
	}
	if (executor.getGrade() > this->getExecuteGrade())
		throw PresidentialPardonForm::GradeTooLowException();

	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	return true;
}