/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:09:41 by dkros             #+#    #+#             */
/*   Updated: 2025/09/09 22:13:45 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade)
	: _name(name)
{
	std::cout << "Default constructor called for Bureaucrat " << name << "." << std::endl;
	try
	{
		if (_name.empty()) {
			throw(std::invalid_argument("invalid_argument: name is required"));
		}
		if (grade > 150) {
			throw(Bureaucrat::GradeTooLowException("GradeTooLowException: grade should be higher than 150"));
		}
		if (grade < 1) {
			throw(Bureaucrat::GradeTooHighException("GradeTooHighException: grade should be lower than 1"));
		}
		_grade = grade;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
		exit(1);
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
	:_name(copy._name)
{
	std::cout << "Copy constructor called for Bureaucrat " << _name << "." << std::endl;
	_grade = copy._grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destroyed" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy)
{
	std::cout << "Assignment operator called for Bureaucrat " << _name << "." << std::endl;
	this->_grade = copy._grade;
	return *this;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string msg)
{
	message = msg;
}

const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
	return message.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string msg)
{
	message = msg;
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
	return message.c_str();
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

std::string Bureaucrat::getName() const
{
	return _name;
}

void Bureaucrat::increment()
{
	try 
	{
		if (_grade - 1 < 1) {
			throw(Bureaucrat::GradeTooHighException("GradeTooHighException: grade should be lower than 1"));
		}
		_grade -= 1;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::decrement()
{
	try 
	{
		if (_grade + 1 > 150) {
			throw(Bureaucrat::GradeTooLowException("GradeTooLowException: grade should be higher than 150"));
		}
		_grade += 1;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::signForm(Form &form)
{
	if (!form.beSigned(*this)) {
		std::cout << _name << " couldn't sign " << form.getName() << " because it's grade is too low." << std::endl;
	} else {
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
}

std::ostream &operator<<(std::ostream & os, const Bureaucrat &input) {

	os << input.getName() << ", bureaucrat grade " << input.getGrade();
	return os;
}