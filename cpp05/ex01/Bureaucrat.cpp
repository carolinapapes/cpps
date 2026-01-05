/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:55:52 by capapes           #+#    #+#             */
/*   Updated: 2025/12/05 10:50:40 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade)
	: _name(name), _grade(grade) {
		_validateGrade(grade);
	}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: _name(other._name), _grade(other._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		_grade = other._grade;
	}
	return *this;
}

const std::string &Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::_validateGrade(int grade) const {
	if (grade < _minGrade) {
		throw GradeTooHighException();
	} else if (grade > _maxGrade) {
		throw GradeTooLowException();
	}
}

void Bureaucrat::incrementGrade() {
	_validateGrade(_grade - 1);
	--_grade;
}

void Bureaucrat::decrementGrade() {
	_validateGrade(_grade + 1);
	++_grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

// EX01
void Bureaucrat::signForm(Form& form) const {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	} catch (const std::exception &e) {
		std::cout << _name << " couldn't sign " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}
