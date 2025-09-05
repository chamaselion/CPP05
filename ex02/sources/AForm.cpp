/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42helbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:24:11 by bszikora          #+#    #+#             */
/*   Updated: 2025/09/04 21:17:30 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

///////////ex01///////////
#include "AForm.hpp"

AForm::AForm() : name("NameMe"), signd(false), req_sign(1), req_exec(1) { }
AForm::AForm(std::string name, bool signd, int req_sign, int req_exec) : name(name), signd(signd), req_sign(req_sign), req_exec(req_exec)
{
	if (this->req_sign < 1 || this->req_exec < 1)
		throw AForm::GradeTooHighException();
	if (this->req_sign > 150 || this->req_exec > 150)
		throw AForm::GradeTooLowException();


}
AForm::AForm(const AForm& other) : name(other.name), signd(other.signd), req_sign(other.req_sign), req_exec(other.req_exec) { }

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		signd = other.signd;
	return *this;
}

AForm::~AForm() { }

std::string	AForm::getName() const { return this->name; }

bool		AForm::getSignd() const { return this->signd; }

int			AForm::getReqSign() const { return this->req_sign; }

int			AForm::getReqExec() const { return this->req_exec; }

void		AForm::beSigned(Bureaucrat signer)
{
	if (signer.getGrade() > this->req_sign)
		throw AForm::GradeTooLowException();
	if (this->signd == true)
	{
		std::cout << signer.getName() << " couldn't sign " << this->name;
		std::cout << " because it's already signed\n";
		return ;
	}
	if ( this->signd == false)
		{
		this->signd = true;
		std::cout << signer.getName() << " signed " << this->name << std::endl;
	}
}

const char* AForm::GradeTooHighException::what() const throw() { return ("Na-ah-aah, that grade is too high"); }

const char* AForm::GradeTooLowException::what() const throw() { return ("Na-ah-aah, that grade is too low"); }

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << f.getName() << ", required grade to sign: " << f.getReqSign();
	os << ", required grade to execute " << f.getReqExec();
	os << ", it is currently " << (f.getSignd() ? "signed." : "not signed.");
    return os;
}

void		AForm::execute(Bureaucrat const &executor) const
{
	
}