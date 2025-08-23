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
# include <stdlib.h>
# include <ctime>

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

bool RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned()) {
		std::cout << this->getName() << " RobotomyRequestFormis is not signed yet" << std::endl;
		return false;
	}
	if (executor.getGrade() > this->getExecuteGrade())
		throw RobotomyRequestForm::GradeTooLowException();

	std::cout << this->getName() << " is making some drilling noises" << std::endl;
	srand(time(0));
	int randNumber = rand() % 1000000;
	if (randNumber % 2 == 0)
		std::cout << this->getName() << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
	return true;
}