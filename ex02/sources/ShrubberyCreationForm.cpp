/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42helbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:16:26 by bszikora          #+#    #+#             */
/*   Updated: 2025/09/15 13:00:18 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

///////////ex02///////////
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", false, 145, 137), name("NameMe") { }
ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm("ShrubberyCreationForm", false, 145, 137), name(name) { }

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other), name(other.name) { }

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->name = other.name; 
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() { }

void	ShrubberyCreationForm::action() const
{
	std::string		filename = this->name + "_shrubbery";
	std::ofstream	file(filename.c_str());
	int 			height = 100;

	if (!file.is_open())
	{
		std::cerr << "Error: Could not create file " << filename << std::endl;
		return;
	}

		for (int i = 1; i <= height; ++i)
		{
			for (int j = 0; j < height - i; ++j)
			{
				file << " ";
			}
			for (int k = 0; k < (2 * i - 1); ++k)
			{
				file << "*";
			}
			file << std::endl;
		}
	for (int i = 0; i < height / 3; ++i)
	{
		for (int j = 0; j < height - 1; ++j)
		{
			file << " ";
		}
		file << "||" << std::endl;
	}

	file.close();
	std::cout << "Shrubbery has been created in file: " << filename << std::endl;
}
