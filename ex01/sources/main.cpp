/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42helbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 13:59:52 by bszikora          #+#    #+#             */
/*   Updated: 2025/09/03 19:08:47 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

///////////ex01///////////
#include "Bureaucrat.hpp"
#include "Form.hpp"

static void	printSep(const std::string &title)
{
	std::cout << "\n===== " << title << " =====\n";
}

int	main(void)
{
	// Form basics
	printSep("Form basics");
	Form f1("FormA", false, 3, 2);
	std::cout << f1 << std::endl;
	std::cout << "getName=" << f1.getName() << ", Signd=" << f1.getSignd() << ", ReqSign=" << f1.getReqSign() << ", ReqExec=" << f1.getReqExec() << std::endl;

	// Form copy and assignment
	printSep("Form copy and assignment");
	Form f2(f1);
	std::cout << "copy-constructed f2: " << f2 << std::endl;
	Form f3("Other", false, 10, 10);
	std::cout << "before assignment f3: " << f3 << std::endl;
	f3 = f1;
	std::cout << "after assignment f3: " << f3 << std::endl;

	// Form ctor exceptions
	printSep("Form constructor exceptions");
	try
	{
		Form badHigh("BadHigh", false, 0, 2);
		std::cout << "UNREACHABLE " << badHigh << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "construct BadHigh(req_sign=0) caught: " << e.what() << std::endl;
	}
	try
	{
		Form badLow("BadLow", false, 151, 2);
		std::cout << "UNREACHABLE " << badLow << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "construct BadLow(req_sign=151) caught: " << e.what() << std::endl;
	}
	
	// beSigned and signForm
	printSep("Form::beSigned and Bureaucrat::signForm");
	Bureaucrat boss("Boss", 1);
	Bureaucrat small("SmallBoss", 2);
	Bureaucrat low("Low", 149);

	// Too low to sign
	try
	{
		std::cout << "low tries to beSigned(FormA): ";
		f1.beSigned(low);
		std::cout << "UNEXPECTED: low signed\n";
	}
	catch (const std::exception &e)
	{
		std::cout << "caught: " << e.what() << std::endl;
	}
		std::cout << std::endl;
	
	// Boss signs successfully
	std::cout << "boss.signForm(FormA)" << std::endl;
	boss.signForm(f1);
	std::cout << f1 << std::endl;
		std::cout << std::endl;

	// Already signed path
	std::cout << "small.signForm(FormA) again (already signed)" << std::endl;
	small.signForm(f1);
	std::cout << f1 << std::endl;
		std::cout << std::endl;

	// Fresh form, exactly required grade
	Form f4("FormExact", false, 2, 5);
	std::cout << f4 << std::endl;
	std::cout << "small.signForm(FormExact)" << std::endl;
	small.signForm(f4);
	std::cout << f4 << std::endl;
		std::cout << std::endl;

	// Another already signed attempt
	std::cout << "low.signForm(FormExact) (already signed)" << std::endl;
	low.signForm(f4);
	std::cout << f4 << std::endl;

	printSep("Done");
	return (0);
}