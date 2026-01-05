/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:30:56 by capapes           #+#    #+#             */
/*   Updated: 2026/01/05 21:00:19 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	try {
		Bureaucrat alice("Alice", 3);
		PresidentialPardonForm pardonForm("Charlie");
		RobotomyRequestForm robotomyForm("Dave");
		ShrubberyCreationForm shrubberyForm("Eve");

		std::cout << alice.getName() << ", bureaucrat grade " << alice.getGrade() << std::endl;

		alice.signForm(pardonForm);
		alice.signForm(robotomyForm);
		alice.signForm(shrubberyForm);

		pardonForm.execute(alice);
		robotomyForm.execute(alice);
		shrubberyForm.execute(alice);
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
	
}