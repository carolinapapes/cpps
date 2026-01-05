/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:56:25 by capapes           #+#    #+#             */
/*   Updated: 2025/11/25 18:20:20 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
	: name("Default"), gradeToSign(150), gradeToExecute(150) {}
AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
	: name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1) {
		throw GradeTooHighException();
	} else if (gradeToSign > 150 || gradeToExecute > 150) {
		throw GradeTooLowException();
	}
}	
AForm::AForm(const AForm& other)
	: name(other.name), isSigned(other.isSigned),
	  gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}
AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		this->isSigned = other.isSigned;
	}
	return *this;
}
AForm::~AForm() {}	

void AForm::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > gradeToSign) {
		throw GradeTooLowException();
	}
	isSigned = true;
}


  void AForm::execute(Bureaucrat const &executor) const {
	if (!isSigned) {
		throw GradeTooLowException();
	}
	if (executor.getGrade() > gradeToExecute) {
		throw GradeTooLowException();
	}
	performAction();
}   

const char *AForm::GradeTooHighException::what() const noexcept
{
	return "Form grade too high!";
}

const char *AForm::GradeTooLowException::what() const noexcept
{
	return "Form grade too low!";
}



