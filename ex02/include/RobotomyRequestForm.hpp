/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42helbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:16:47 by bszikora          #+#    #+#             */
/*   Updated: 2025/09/06 16:37:47 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
private:
	std::string		name;
	virtual void	action() const;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string name);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	class RobotomyFailedException : public std::exception
	{
		public:
		
		virtual const char* what() const throw();
	};
};

void	printSep(const std::string &title);

#endif