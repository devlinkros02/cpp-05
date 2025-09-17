/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 18:13:51 by dkros             #+#    #+#             */
/*   Updated: 2025/09/16 20:15:00 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137) {

	_target = target;
	_isSigned = false;
	std::cout << "Constructor called for ShrubberyCreationForm with target " << target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm("ShrubberyCreationForm", 145, 137) {
	
	_target = copy._target;
	_isSigned = copy._isSigned;
	std::cout << "Copy constructor called for ShrubberyCreationForm with target " << copy._target << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {

	std::cout << "Destructor called for ShrubberyCreationForm with target " << _target << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) {

	if (this != &copy) {
		_target = copy._target;
		_isSigned = copy._isSigned;
		std::cout << "Assignment operator called for ShrubberyCreationForm with target " << copy._target << std::endl;
	}
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {

	(void)executor;
	std::ofstream outfile ("test.txt");
	outfile << "test" << std::endl;
	outfile.close();
}