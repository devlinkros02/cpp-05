/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:16:03 by dkros             #+#    #+#             */
/*   Updated: 2025/09/09 22:10:23 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExec)
	:_name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	try
	{
		if (gradeToSign < 1 || gradeToExec < 1)
			throw Form::GradeTooHighException("GradeTooHighException: gradeToSign and gradeToExec must be lower than 1.");
		if (gradeToSign > 150 || gradeToExec > 150)
			throw Form::GradeTooLowException("GradeTooLowException: gradeToSign and gradeToExec must be higher than 150.");
		this->_isSigned = false;
		std::cout << "Default constructor called for Form " << name << "." << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Form::Form(const Form &copy)
	:_name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExec(copy._gradeToExec)
{
	this->_isSigned = copy._isSigned;
	std::cout << "Copy constructor called for Form " << _name << "." << std::endl;
}

Form::~Form()
{
	std::cout << "Destructor called for Form " << _name << "." << std::endl;
}

Form &Form::operator=(const Form &copy)
{
	this->_isSigned = copy._isSigned;
	std::cout << "Assignment operator called for Form " << _name << "." << std::endl;
	return *this;
}

Form::GradeTooHighException::GradeTooHighException(std::string msg) {

	message = msg;
}

const char *Form::GradeTooHighException::what() const noexcept {

	return message.c_str();
}

Form::GradeTooLowException::GradeTooLowException(std::string msg) {

	message = msg;
}

const char *Form::GradeTooLowException::what() const noexcept {

	return message.c_str();
}

std::string Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExec() const
{
	return _gradeToExec;
}

bool Form::beSigned(const Bureaucrat &bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() > getGradeToSign()) {
			throw(Form::GradeTooLowException("GradeTooLowException: This Bureaucrat's grade is too low to sign this form."));
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

std::ostream &operator<<(std::ostream & os, const Form &input) {

	os << input.getName() << ", form with grade to sign: " << input.getGradeToSign() << ", grade to execute: " << input.getGradeToExec() << ", isSigned is " << input.getIsSigned() << std::endl;
	return os;
}