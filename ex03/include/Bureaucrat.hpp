/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42helbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 13:59:34 by bszikora          #+#    #+#             */
/*   Updated: 2025/09/05 22:38:47 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

///////////ex01///////////
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string	name;
	int 				grade; //1 - 150

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	std::string			getName() const;
	int					getGrade() const;
	void				incrementGrade();
	void				decrementGrade();
	void				executeForm(AForm const & form) const;

	class GradeTooHighException : public std::exception
	{
		public:

		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
		
		virtual const char* what() const throw();
	};
	///ex01///
	void signForm(AForm& form) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif