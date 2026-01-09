/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:30:56 by capapes           #+#    #+#             */
/*   Updated: 2026/01/06 16:15:56 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(){
	try {
		Bureaucrat bob("Bob", 2);
		std::cout << bob << std::endl;

		bob.incrementGrade();
		std::cout << "After increment: " << bob << std::endl;

		bob.incrementGrade();
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat alice("Alice", 149);
		std::cout << alice << std::endl;

		alice.decrementGrade();
		std::cout << "After decrement: " << alice << std::endl;

		alice.decrementGrade();
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat invalidHigh("InvalidHigh", 0);
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat invalidLow("InvalidLow", 151);
	} catch (const std::exception &e) {
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

// This exercise
// - [x] Implement a Bureaucrat class with const name and grade attributes
// - [x] Grade must be between 1 (highest) and 150 (lowest)
// - [x] Implement increment and decrement methods for the grade - members
// - [x] if the grade goes out of bounds, throw exceptions
// - [x] Grade 1 is the highest, 150 is the lowest, incrementing the grade means decreasing the numerical value
// - [x] Throw exeptions must be catchable using try and catch blocks
// - [x] Implement overload of the insertion operator (<<) to output Bureaucrat details
// - [x] Throw exceptions for grade violations using custom exception classes
// - [x] Provide getter methods for name and grade

