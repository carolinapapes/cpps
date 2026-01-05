/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:30:56 by capapes           #+#    #+#             */
/*   Updated: 2025/12/05 10:20:35 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// General instructions
// - [ ] Compile with C++ and the flags -Wall -Wextra -Werror
// - [ ] Compile with the flag -std=c++98
// - [ ] Name directory of the project ex00, ex01, etc. according to the exercise number
// - [ ] Files must be named as the class they contain. 
// - [ ] Class declaration in .hpp file and class implementation in .cpp file
// - [ ] Class names must be in CamelCase and start with a capital letter
// - [ ] Output messages must end with a newline character and be printed on the standard output or standard error as specified

// Design notes
// - [ ] Avoid memory leaks when using `new` by ensuring that every `new` has a corresponding `delete`
// - [ ] Follow the Orthodox Canonical Form for all your classes
// - [ ] No functions implementations on header files, except for functions templates
// - [ ] Include guards or `#pragma once` in header files to prevent multiple inclusions

// Exercise 00 requirements
// - [ ] Implement a Bureaucrat class with const name and grade attributes
// - [ ] Grade must be between 1 (highest) and 150 (lowest)
// - [ ] Implement increment and decrement methods for the grade - members
// - [ ] if the grade goes out of bounds, throw exceptions
// - [ ] Grade 1 is the highest, 150 is the lowest, incrementing the grade means decreasing the numerical value
// - [ ] Throw exeptions must be catchable using try and catch blocks
// - [ ] Implement overload of the insertion operator (<<) to output Bureaucrat details
// - [ ] Throw exceptions for grade violations using custom exception classes
// - [ ] Provide getter methods for name and grade

// Exercise 01 requirements
// - [ ] Same as ex00
// - [ ] Create a Form class
// - [ ] Form has a const name
// - [ ] A boolean indicating if it's signed
// - [ ] A constant grade required to execute
// - [ ] All attributes must be private not protected
// - [ ] Grades have the same restrictions as in Bureaucrat
// - [ ] Implement beSigned method that takes a Bureaucrat and signs the form if the Bureaucrat's grade is high enough
// - [ ] If the grade is too low, throw an exception
// - [ ] Implement the method singForm that takes a Bureaucrat and attempts to sign the form, printing appropriate messages

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