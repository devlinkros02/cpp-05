/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:29:04 by dkros             #+#    #+#             */
/*   Updated: 2025/09/09 20:05:35 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(int argc, char **argv) {

	if (argc != 3) {
		std::cout << "Please provide 2 arguments name and grade. Example: ./bureaucrat Devlin 20" << std::endl;
		return (1);
	}

	//Convert input grade to int
	std::string input = argv[2];
	int grade = atoi(input.c_str());

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

	return (0);
}