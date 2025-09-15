/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42helbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 20:54:31 by bszikora          #+#    #+#             */
/*   Updated: 2025/09/15 13:07:11 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

///////////ex03s///////////
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()  : AForm("RobotomyRequestForm", false, 72, 45 ), name("NameMe"){ }

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm("RobotomyRequestForm", false, 72, 45 ), name(name) { }

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), name(other.name) { }

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->name = other.name; 
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() { }

void	printSep(const std::string &title)
{
	std::cout << "\n===== " << title << " =====\n";
}

const char* RobotomyRequestForm::RobotomyFailedException::what() const throw() { return ("Robotomy failed."); }

void	drillingNoise(int count)
{
	for (int i = 0; i < count; i++)
	{
		printSep("\"drilling noise\"");
	}
}

void	RobotomyRequestForm::action() const
{
	drillingNoise(3);
	srand(static_cast<unsigned>(time(0))); 
	if (rand() % 2)
		std::cout << "Robotomized successfully\n";
	else
		throw RobotomyRequestForm::RobotomyFailedException();
}