/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:51:24 by capapes           #+#    #+#             */
/*   Updated: 2025/12/05 10:23:58 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

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

// Exercise 02 requirements
// - [ ] Class form must be renamed AForm and become an abstract base class
// - [ ] All attributes of AForm must remain private and belong to the base class
// - [ ] Create the following concrete classes that inherit from AForm:
//   • ShrubberyCreationForm: Required grades: sign 145, exec 137
//     Creates a file <target>_shrubbery in the working directory and writes ASCII trees inside it.
//   • RobotomyRequestForm: Required grades: sign 72, exec 45
//     Makes some drilling noises, then informs that <target> has been robotomized successfully 50% of the time. Otherwise, it informs that the robotomy failed.
//   • PresidentialPardonForm: Required grades: sign 25, exec 5
//	 Informs that <target> has been pardoned by Zaphod Beeblebrox.
// - [ ] Each concrete class takes only one parameter in their constructor: the target of the form. For example, "home" if you want to plant shrubbery at home.
// - [ ] Add the execute(Bureaucrat const & executor) const member function to the base form and implement a function to execute the form’s action in the concrete classes. You must check that the form is signed
//   and that the grade of the bureaucrat attempting to execute the form is high enough. Otherwise, throw an appropriate exception.
// - [ ] Add the executeForm(AForm const & form) const member function to the Bureaucrat class. It must attempt to execute the form. If successful, print something like:



class Bureaucrat {
	public:
		// Orthodox canonical form
		Bureaucrat(const std::string &name, int grade);	
		~Bureaucrat() = default;
		Bureaucrat(const Bureaucrat &other) = default;
		Bureaucrat &operator=(const Bureaucrat &other) = default;

		// Methods
		const std::string 	&getName() const;
		int 				getGrade() const;
		void				incrementGrade();
		void				decrementGrade();

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const noexcept override;
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const noexcept override;
		};

		void signForm(const AForm& form) const;
	private:
		const std::string 	_name;
		int 				_grade;
		static const int 	_minGrade = 1;
		static const int 	_maxGrade = 150;

		// Methods
		void 				validateGrade(int grade) const;
};

inline std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}