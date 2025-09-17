/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 17:49:11 by dkros             #+#    #+#             */
/*   Updated: 2025/09/16 20:14:45 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	(void)argc;
	try
	{
		Bureaucrat test("Devlin", 50);
		ShrubberyCreationForm test1("test");

		test1.execute(test);
		
		std::cout << test << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		exit(1);
	}
	return (0);
}