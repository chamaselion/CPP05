/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42helbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:58:29 by bszikora          #+#    #+#             */
/*   Updated: 2025/09/06 17:16:16 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

typedef AForm* (*FormCreator)(const std::string&);

Intern::Intern() { }

Intern::Intern(const Intern& other) { (void) other; }

Intern& Intern::operator=(const Intern& other) { (void) other; return *this; }

Intern::~Intern() { }

static AForm* createShrubbery(const std::string& target) { return new ShrubberyCreationForm(target); }

static AForm* createRobotomy(const std::string& target) { return new RobotomyRequestForm(target); }

static AForm* createPresidentialPardon(const std::string& target) { return new PresidentialPardonForm(target); }

AForm* Intern::makeForm(std::string formName, std::string formTarget)
{
	const std::string formTypes[] =
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	FormCreator creators[] =
	{
		createShrubbery,
		createRobotomy,
		createPresidentialPardon
	};

	for (size_t i = 0; i < 3; ++i)
	{
		if (formName == formTypes[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return creators[i](formTarget);
		}
	}

	std::cerr << "Error: Unknown form type '" << formName << "'" << std::endl;
	return NULL;
}

