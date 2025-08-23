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

# include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called\n";
}

Intern::Intern(const Intern& other)
{
	std::cout << "Intern copy constructor called\n";
	*this = other;
}

Intern& Intern::operator=(const Intern& other)
{
	std::cout << "Intern assign operator called\n";
	if (this != &other) {}
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called\n";
}

AForm* createShrubberyCreationForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* createRobotomyRequestForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* createPresidentialPardonForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
	t_creatorForm forms[3] = {
		{"shrubbery creation", &createShrubberyCreationForm},
		{"robotomy request", &createRobotomyRequestForm},
		{"presidential pardon", &createPresidentialPardonForm},
	};

	AForm* newForm;
	for (size_t i = 0; i < 3; i++)
	{
		if (name == forms[i].nameForm) {
			std::cout << "Intern creates " << name << std::endl;
			newForm = forms[i].func(target);
			return newForm;
		}
	}

	std:: cout << "Form " << name << " does not exists. Please, give a valid name\n";
	return NULL;
}
