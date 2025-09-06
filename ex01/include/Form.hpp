/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42helbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:23:58 by bszikora          #+#    #+#             */
/*   Updated: 2025/09/04 21:20:21 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	name;
	bool				signd;
	const int			req_sign;
	const int			req_exec;

public:
	Form();
	Form(std::string name, bool signd, int req_sign, int req_exec);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	std::string	getName() const;
	bool		getSignd() const;
	int			getReqSign() const;
	int			getReqExec() const;
	void		beSigned(const Bureaucrat signer);

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
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif