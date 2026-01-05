/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:30:56 by capapes           #+#    #+#             */
/*   Updated: 2025/12/05 10:22:31 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// test intern
int main() {
	try {
		Bureaucrat bob("Bob", 42);
		std::cout << bob << std::endl;
		bob.incrementGrade();
		std::cout << "After increment: " << bob << std::endl;
		bob.decrementGrade();
		bob.decrementGrade();
		std::cout << "After two decrements: " << bob << std::endl;
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		Bureaucrat john("John", 1);
		std::cout << *rrf << std::endl;
		john.signForm(*rrf);
		rrf->execute(john);
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}