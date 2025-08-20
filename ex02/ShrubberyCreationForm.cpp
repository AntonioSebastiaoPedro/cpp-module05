/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 09:24:16 by ansebast          #+#    #+#             */
/*   Updated: 2025/08/20 02:25:18 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"
# include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm Default", 145, 137)
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name) : AForm(name, 145, 137)
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other ) : AForm(other)
{
	this->setSignGrade(145);
	this->setExecuteGrade(137);
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& other )
{
	if (this != &other)
	{
		this->setName(other.getName());
		this->setIsSigned(other.getIsSigned());
		this->setSignGrade(145);
		this->setExecuteGrade(137);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned()) {
		std::cerr << this->getName() << " ShrubberyCreationForm is not signed yet" << std::endl;
		return ;
	}
	if (executor.getGrade() > this->getExecuteGrade()) {
		throw ShrubberyCreationForm::GradeTooLowException();
	}
	
	std::string filename = this->getName() + "_shrubbery";
	std::ofstream file(filename.c_str());

	file << "               ,@@@@@@@,                  " << std::endl;
	file << "       ,,,.   ,@@@@@@/@@,  .oo8888o.      " << std::endl;
	file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o     " << std::endl;
	file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'    " << std::endl;
	file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'    " << std::endl;
	file << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'     " << std::endl;
	file << "   `&%\\ ` /%&'    |.|        \\ '|8'       " << std::endl;
	file << "       |o|        | |         | |         " << std::endl;
	file << "       |.|        | |         | |         " << std::endl;
	file << "       |o|        | |         | |   " << std::endl;
	file << std::endl;
	file << "              /\\                          " << std::endl;
	file << "             /  \\                         " << std::endl;
	file << "            /    \\                        " << std::endl;
	file << "           /      \\                       " << std::endl;
	file << "          /        \\                      " << std::endl;
	file << "         /__________\\                     " << std::endl;
	file << "             |  |                         " << std::endl;
	file << "             |__|                         " << std::endl;
	
	file.close();
}