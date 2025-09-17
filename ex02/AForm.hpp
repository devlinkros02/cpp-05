/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:15:56 by dkros             #+#    #+#             */
/*   Updated: 2025/09/16 17:52:35 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include <fstream>

#pragma once

class Bureaucrat;

class AForm {

	protected:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExec;

	public:
		AForm(std::string name, int gradeToSign, int gradeToExec);
		AForm(const AForm &copy);
		virtual ~AForm();

		AForm &operator=(const AForm &copy);

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
		virtual	void		execute(const Bureaucrat &executor) const = 0;
};

std::ostream & operator<<(std::ostream & o, AForm const & input);
