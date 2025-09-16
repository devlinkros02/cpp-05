/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:29:04 by dkros             #+#    #+#             */
/*   Updated: 2025/09/16 17:17:24 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

bool is_numeric(const std::string &string) {

	for (std::string::const_iterator i = string.begin(); i != string.end(); i++ ) {
		if (!std::isdigit(*i)) {
			return (false);
		}
	}
	return true;
}

int main(int argc, char **argv) {

	try {

		if (argc != 3) {
			throw(std::invalid_argument("Please provide 2 arguments name and grade. Example: ./bureaucrat Devlin 20"));
		}

		if (!is_numeric(argv[2]))  {
			throw (std::invalid_argument("Invalid grade."));
		}

		int grade = atoi(argv[2]);

		//Create Bureaucrat with given arguments
		Bureaucrat test(argv[1], grade);

		// Test to see if the Bureaucrat was succesfully made
		std::cout << "Name: " << test.getName() << std::endl;
		std::cout << "Grade: " << test.getGrade() << std::endl;

		test.increment();
		std::cout << "Grade: " << test.getGrade() << std::endl;
		test.decrement();
		std::cout << "Grade: " << test.getGrade() << std::endl;
		test.decrement();
		test.decrement();
		test.decrement();
		std::cout << "Grade: " << test.getGrade() << std::endl;

		//Final test to see if the ostream overload works
		std::cout << "Final test:" << std::endl;
		std::cout << test << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << "Error: " << e.what() <<  std::endl;
		exit(1);
	}

	return (0);
}