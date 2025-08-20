/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 09:24:16 by ansebast          #+#    #+#             */
/*   Updated: 2025/08/20 02:25:18 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"
# include <fstream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm Default", 72, 45)
{
	
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& name) : AForm(name, 72, 45)
{
	
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& other ) : AForm(other)
{
	this->setSignGrade(72);
	this->setExecuteGrade(45);
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& other )
{
	if (this != &other)
	{
		this->setName(other.getName());
		this->setIsSigned(other.getIsSigned());
		this->setSignGrade(72);
		this->setExecuteGrade(45);
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{

}