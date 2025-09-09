/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:15:56 by dkros             #+#    #+#             */
/*   Updated: 2025/09/09 21:45:11 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>

#pragma once

class Bureaucrat;

class Form {

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExec;

	public:
		Form(std::string name, int gradeToSign, int gradeToExec);
		Form(const Form &copy);
		~Form();

		Form &operator=(const Form &copy);

		class GradeTooHighException: public std::exception {
			private:
				std::string message;
			public:
				GradeTooHighException(std::string msg);

				const char *what() const noexcept;
		};

		class GradeTooLowException: public std::exception {
			private:
				std::string message;
			public:
				GradeTooLowException(std::string msg);

				const char *what() const noexcept;
		};

		std::string			getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExec() const;
		bool				beSigned(const Bureaucrat &bureaucrat);
};

std::ostream & operator<<(std::ostream & o, Form const & input);
