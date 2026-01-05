/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:43:54 by capapes           #+#    #+#             */
/*   Updated: 2025/12/05 10:24:18 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

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

class AForm
{
	private:
	const std::string 	_name;
	bool 				_isSigned = false;
	int const 			_gradeToSign;
	int const 			_gradeToExecute;
	
	protected:
	class GradeTooHighException : public std::exception {
		public:
		const char *what() const noexcept override;
	};
	class GradeTooLowException : public std::exception {
		public:
		const char *what() const noexcept override;
	};
	
	public:
	// Orthodox canonical form
	AForm();
	AForm(std::string name, int gradeToSign, int gradeToExecute);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	~AForm();
	const std::string& getName() const { return _name; }
	bool getIsSigned() const { return _isSigned; }
	void beSigned(Bureaucrat& bureaucrat);
	void execute(Bureaucrat const &executor) const;   // public final behavior

protected:
    virtual void performAction() const = 0;   
};

inline std::ostream &operator<<(std::ostream &os, const AForm &form) {
	os << "Form Name: " << form.getName() 
	<< ", Signed: " << (form.getIsSigned() ? "Yes" : "No");
	return os;
}






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

// Exercise 03 requirements
	
// 	Since filling out forms all day would be too cruel for our bureaucrats, interns exist to
// take on this tedious task. In this exercise, you must implement the Intern class. The
// intern has no name, no grade, and no unique characteristics. The only thing bureaucrats
// care about is that they do their job.
// However, the intern has one key ability: the makeForm() function. This function
// takes two strings as parameters: the first one represents the name of a form, and the
// second one represents the target of the form. It returns a pointer to a AForm object
// (corresponding to the form name passed as a parameter), with its target initialized to
// the second parameter.
// It should print something like:
// Intern creates <form>
// If the provided form name does not exist, print an explicit error message.