/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 09:03:47 by ansebast          #+#    #+#             */
/*   Updated: 2025/08/20 02:06:13 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public virtual AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& form);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& form);
		ShrubberyCreationForm(const std::string& name);
		~ShrubberyCreationForm();
		
		void execute(Bureaucrat const & executor) const;
};

#endif