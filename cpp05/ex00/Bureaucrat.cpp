/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:55:52 by capapes           #+#    #+#             */
/*   Updated: 2026/01/06 16:36:16 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// ========================================================
// Orthodox canonical form
// ========================================================

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: _name(other._name), _grade(other._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}


// ========================================================
// Specific constructor
// ========================================================

Bureaucrat::Bureaucrat(const std::string &name, int grade)
	: _name(name), _grade(grade) {
	_validateGrade(grade);
}


// ========================================================
// Getters
// ========================================================

const std::string &Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}


// ========================================================
// Methods
// ========================================================

void Bureaucrat::incrementGrade() {
	_validateGrade(_grade - 1);
	--_grade;
}

void Bureaucrat::decrementGrade() {
	_validateGrade(_grade + 1);
	++_grade;
}


// ========================================================
// Exceptions
// ========================================================

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}


// ========================================================
// Pivate methods
// ========================================================

void Bureaucrat::_validateGrade(int grade) const {
	if (grade < _minGrade) {
		throw GradeTooHighException();
	} else if (grade > _maxGrade) {
		throw GradeTooLowException();
	}
}


// ========================================================
// Stream output
// ========================================================

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
