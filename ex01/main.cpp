/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:29:04 by dkros             #+#    #+#             */
/*   Updated: 2025/09/09 22:22:08 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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

	std::cout << test << std::endl;

	Form contract("Contract", 220, 50);
	std::cout << contract << std::endl;

	test.signForm(contract);
	std::cout << contract << std::endl;
	test.increment();
	std::cout << test << std::endl;
	test.increment();
	std::cout << test << std::endl;
	test.increment();
	std::cout << test << std::endl;

	test.signForm(contract);
	std::cout << contract << std::endl;

	return (0);
}