/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:43:54 by capapes           #+#    #+#             */
/*   Updated: 2025/12/05 10:15:37 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class AForm
{
	private:
	const std::string name;
	bool isSigned = false;
	int const gradeToSign;
	int const gradeToExecute;
	
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
	const std::string& getName() const { return name; }
	bool getIsSigned() const { return isSigned; }
	void beSigned(const Bureaucrat& bureaucrat);
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
	