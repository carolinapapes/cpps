/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:51:24 by capapes           #+#    #+#             */
/*   Updated: 2026/01/05 20:16:04 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>

class Form;

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
// - [ ] Form has a const name
// - [ ] A boolean indicating if it's signed
// - [ ] A constant grade required to execute
// - [ ] All attributes must be private not protected
// - [ ] Grades have the same restrictions as in Bureaucrat
// - [ ] Implement beSigned method that takes a Bureaucrat and signs the form if the Bureaucrat's grade is high enough
// - [ ] If the grade is too low, throw an exception
// - [x] Implement the method singForm that takes a Bureaucrat and attempts to sign the form, printing appropriate messages

class Bureaucrat {
	public:
		// Orthodox canonical form
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);

		Bureaucrat(const std::string &name, int grade);	
		// Methods
		const std::string 	&getName() const;
		int 				getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(Form& form) const; // EX01

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:
		const std::string 	_name;
		int 				_grade;
		static const int 	_minGrade = 1;
		static const int 	_maxGrade = 150;

		// Methods
		void 				_validateGrade(int grade) const;
};

inline std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}