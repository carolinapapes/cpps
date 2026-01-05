/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:56:25 by capapes           #+#    #+#             */
/*   Updated: 2026/01/05 20:23:31 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
	: _name("Default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute){
	if (gradeToSign < 1 || gradeToExecute < 1) {
		throw GradeTooHighException();
	} else if (gradeToSign > 150 || gradeToExecute > 150) {
		throw GradeTooLowException();
	}
}

Form::Form(const Form& other)
	: _name(other.getName()), _isSigned(other.getIsSigned()),
	  _gradeToSign(other.getGradeToSign()), _gradeToExecute(other.getGradeToExecute()) {}

//TODO: REVISAR
Form& Form::operator=(const Form& other) {
	if (this != &other) {
		this->_isSigned = other._isSigned;
	}
	return *this;
}

Form::~Form() {}	

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign) {
		throw GradeTooLowException();
	}
	_isSigned = true;
}

bool Form::getIsSigned() const {
	return _isSigned;
}

const std::string& Form::getName() const {
	return _name;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExecute() const {
	return _gradeToExecute;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Form grade too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form grade too low!";
}



