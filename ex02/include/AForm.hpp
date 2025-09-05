/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42helbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:23:58 by bszikora          #+#    #+#             */
/*   Updated: 2025/09/04 21:16:06 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	name;
	bool				signd;
	const int			req_sign;
	const int			req_exec;

protected:
	virtual void		action() const = 0;

public:
	AForm();
	AForm(std::string name, bool signd, int req_sign, int req_exec);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	~AForm();

	std::string	getName() const;
	bool		getSignd() const;
	int			getReqSign() const;
	int			getReqExec() const;
	void		beSigned(const Bureaucrat signer);
	void		execute(Bureaucrat const &executor) const;

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

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif