/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42helbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 13:59:52 by bszikora          #+#    #+#             */
/*   Updated: 2025/08/31 15:20:55 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	{
		Bureaucrat tester_empty;
		Bureaucrat tester_good = Bureaucrat("good", 150);

		try
		{
			Bureaucrat tester_high = Bureaucrat("high", 0);
			std::cout << tester_high.getName() << " " << tester_high.getGrade() << std::endl;
		}
		catch (const Bureaucrat::GradeTooHighException& e)
		{
			std::cout << "Exception caught for high grade: " << e.what() << std::endl;
		}

		try
		{
			Bureaucrat tester_low = Bureaucrat("low", 151);
			std::cout << tester_low.getName() << " " << tester_low.getGrade() << std::endl;
		}
		catch (const Bureaucrat::GradeTooLowException& e)
		{
			std::cout << "Exception caught for low grade: " << e.what() << std::endl;
		}

		std::cout << tester_empty.getName() << " " << tester_empty.getGrade() << std::endl;
		std::cout << tester_good.getName() << " " << tester_good.getGrade() << std::endl;
	std::cout << std::endl << std::endl;
	}

	{
	Bureaucrat tester_increment_good = Bureaucrat("increment_good", 2);
	Bureaucrat tester_increment_bad = Bureaucrat("increment_bad", 1);
	Bureaucrat tester_decrement_good = Bureaucrat("decrement_good", 149);
	Bureaucrat tester_decrement_bad = Bureaucrat("decrement_bad", 150);

	try
	{
		tester_increment_good.incrementGrade(); 
		std::cout << tester_increment_good.getName() << " grade after increment: " << tester_increment_good.getGrade() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "Exception caught for increment_good: " << e.what() << std::endl;
	}

	try
	{
		tester_increment_bad.incrementGrade();
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "Exception caught for increment_bad: " << e.what() << std::endl;
	}

	try
	{
		tester_decrement_good.decrementGrade();
		std::cout << tester_decrement_good.getName() << " grade after decrement: " << tester_decrement_good.getGrade() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "Exception caught for decrement_good: " << e.what() << std::endl;
	}

	try
	{
		tester_decrement_bad.decrementGrade();
		std::cout << tester_decrement_bad.getName() << " grade after decrement: " << tester_decrement_bad.getGrade() << std::endl;
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "Exception caught for decrement_bad: " << e.what() << std::endl;
	}
	std::cout << std::endl << std::endl;
	}

	{
	Bureaucrat random;
	Bureaucrat arged = Bureaucrat("itsame", 150);

	std::cout << random << std::endl;
	std::cout << arged << std::endl;
	}
	return 0;
}