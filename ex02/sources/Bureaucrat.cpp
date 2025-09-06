/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42helbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 14:00:32 by bszikora          #+#    #+#             */
/*   Updated: 2025/09/06 16:54:35 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

///////////ex02///////////
#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("NameMe"), grade(150) { }

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	this->grade = 150;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : 	name(other.name), grade(other.grade) { }

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		grade = other.grade;
	}
	return *this;
}

	std::string	Bureaucrat::getName() const
	{
		return name;
	}
	int	Bureaucrat::getGrade() const
	{
		return grade;
	}
	void				Bureaucrat::incrementGrade()
	{
		int checker = grade;
		checker--;
		if (checker < 1)
		{
			throw Bureaucrat::GradeTooHighException();
		}
		grade--;
	}
	void				Bureaucrat::decrementGrade()
	{
		int checker = grade;
		checker++;
		if (checker > 150)
		{
			throw Bureaucrat::GradeTooLowException();
		}
		grade++;
	}

Bureaucrat::~Bureaucrat() { }

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Na-ah-aah, that grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Na-ah-aah, that grade is too low");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}

///ex01///
void Bureaucrat::signForm(AForm& form) const
{
	try
	{
		form.beSigned(*this);
	}
	catch (const std::exception& e)
	{
		std::cout << getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}