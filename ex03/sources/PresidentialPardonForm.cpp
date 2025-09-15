/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42helbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:17:49 by bszikora          #+#    #+#             */
/*   Updated: 2025/09/15 13:07:12 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

///////////ex03///////////
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", false, 25, 5), name("NameMe") { }

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm("PresidentialPardonForm", false, 25, 5), name(name) { }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), name(other.name) { }

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->name = other.name; 
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() { }

void	PresidentialPardonForm::action() const
{
	std::cout << this->name << " has been pardoned by Zaphod Beeblebrox\n";
}
