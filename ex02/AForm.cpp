/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:16:03 by dkros             #+#    #+#             */
/*   Updated: 2025/09/16 17:10:42 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExec)
	:_name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{

	if (gradeToSign < 1 || gradeToExec < 1)
		throw AForm::GradeTooHighException("AForm::GradeTooHighException: gradeToSign and gradeToExec must be lower than 1.");
	if (gradeToSign > 150 || gradeToExec > 150)
		throw AForm::GradeTooLowException("AForm::GradeTooLowException: gradeToSign and gradeToExec must be higher than 150.");
	this->_isSigned = false;
	std::cout << "Default constructor called for AForm " << name << "." << std::endl;

}

AForm::AForm(const AForm &copy)
	:_name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExec(copy._gradeToExec)
{
	this->_isSigned = copy._isSigned;
	std::cout << "Copy constructor called for AForm " << _name << "." << std::endl;
}

AForm::~AForm()
{
	std::cout << "Destructor called for AForm " << _name << "." << std::endl;
}

AForm &AForm::operator=(const AForm &copy)
{
	this->_isSigned = copy._isSigned;
	std::cout << "Assignment operator called for AForm " << _name << "." << std::endl;
	return *this;
}

AForm::GradeTooHighException::GradeTooHighException(std::string msg) {

	message = msg;
}

const char *AForm::GradeTooHighException::what() const noexcept {

	return message.c_str();
}

AForm::GradeTooLowException::GradeTooLowException(std::string msg) {

	message = msg;
}

const char *AForm::GradeTooLowException::what() const noexcept {

	return message.c_str();
}

std::string AForm::getName() const
{
	return _name;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExec() const
{
	return _gradeToExec;
}

bool AForm::beSigned(const Bureaucrat &bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() > getGradeToSign()) {
			throw(AForm::GradeTooLowException("AForm::GradeTooLowException: This Bureaucrat's grade is too low to sign this AForm."));
		}
		_isSigned = true;
		return true;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
		return false;
	}
}

std::ostream &operator<<(std::ostream & os, const AForm &input) {

	os << input.getName() << ", AForm with grade to sign: " << input.getGradeToSign() << ", grade to execute: " << input.getGradeToExec() << ", isSigned is " << input.getIsSigned() << std::endl;
	return os;
}