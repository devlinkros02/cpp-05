/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:10:03 by dkros             #+#    #+#             */
/*   Updated: 2025/09/16 18:01:35 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>

#pragma once

class AForm;

class Bureaucrat {

	private:
		std::string const	_name;
		unsigned int 		_grade;
	
	public:
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat &copy);

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

		std::string 		getName() const;
		int					getGrade() const;
		void				increment();
		void				decrement();
		void				signForm(AForm &AForm);
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & input);
