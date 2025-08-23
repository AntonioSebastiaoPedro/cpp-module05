/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ansebast <ansebast@student.42luanda.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 09:03:47 by ansebast          #+#    #+#             */
/*   Updated: 2025/08/20 02:49:47 by ansebast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PRESEDENTIAL_PARDON_FORM_HPP
# define PRESEDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public virtual AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& form);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& form);
		PresidentialPardonForm(const std::string& name);
		~PresidentialPardonForm();
		
		bool execute(Bureaucrat const & executor) const;
};

#endif