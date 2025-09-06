/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42helbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:13:56 by bszikora          #+#    #+#             */
/*   Updated: 2025/09/06 16:26:40 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
	RobotomyRequestForm testR = RobotomyRequestForm("testerR");
	// PresidentialPardonForm testP = PresidentialPardonForm("testerP");
	// ShrubberyCreationForm testS = ShrubberyCreationForm("testerS");
	Bureaucrat low = Bureaucrat("low", 149);
	Bureaucrat high = Bureaucrat("high", 1);

	high.signForm(testR);

	low.executeForm(testR);
	high.executeForm(testR);
	return 0;
}