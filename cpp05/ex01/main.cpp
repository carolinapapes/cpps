/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:30:56 by capapes           #+#    #+#             */
/*   Updated: 2026/01/06 16:22:44 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Bureaucrat bob("Bob", 6);
		Form taxForm("Tax Form", 5, 10);

		std::cout << bob << std::endl;
		std::cout << taxForm << std::endl;

		bob.signForm(taxForm);
		std::cout << "After signing attempt: \n" << taxForm << "\n"<< std::endl;

		bob.incrementGrade();
		std::cout << bob << std::endl;
		bob.signForm(taxForm);
		std::cout << "After second signing attempt: " << taxForm << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		
	}
	return 0;
}

// General instructions
// - [x] Compile with C++ and the flags -Wall -Wextra -Werror
// - [x] Compile with the flag -std=c++98
// - [x] Name directory of the project ex00, ex01, etc. according to the exercise number
// - [x] Files must be named as the class they contain. 
// - [x] Class declaration in .hpp file and class implementation in .cpp file
// - [x] Class names must be in CamelCase and start with a capital letter
// - [x] Output messages must end with a newline character and be printed on the standard output or standard error as specified

// Design notes
// - [x] Avoid memory leaks when using `new` by ensuring that every `new` has a corresponding `delete`
// - [x] Follow the Orthodox Canonical Form for all your classes
// - [x] No functions implementations on header files, except for functions templates
// - [x] Include guards or `#pragma once` in header files to prevent multiple inclusions

// Exercise 00 requirements
// - [x] Implement a Bureaucrat class with const name and grade attributes
// - [x] Grade must be between 1 (highest) and 150 (lowest)
// - [x] Implement increment and decrement methods for the grade - members
// - [x] if the grade goes out of bounds, throw exceptions
// - [x] Grade 1 is the highest, 150 is the lowest, incrementing the grade means decreasing the numerical value
// - [x] Throw exeptions must be catchable using try and catch blocks
// - [x] Implement overload of the insertion operator (<<) to output Bureaucrat details
// - [x] Throw exceptions for grade violations using custom exception classes
// - [x] Provide getter methods for name and grade

// Exercise 01 requirements
// - [x] Same as ex00
// - [x] Create a Form class
// - [x] Form has a const name
// - [x] A boolean indicating if it's signed
// - [x] A constant grade required to execute
// - [x] All attributes must be private not protected
// - [x] Grades have the same restrictions as in Bureaucrat
// - [x] Implement beSigned method that takes a Bureaucrat and signs the form if the Bureaucrat's grade is high enough
// - [x] If the grade is too low, throw an exception
// - [x] Implement the method singForm that takes a Bureaucrat and attempts to sign the form, printing appropriate messages
