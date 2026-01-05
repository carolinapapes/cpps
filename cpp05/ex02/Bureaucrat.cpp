/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:55:52 by capapes           #+#    #+#             */
/*   Updated: 2025/12/04 16:38:10 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

inline Bureaucrat::Bureaucrat(const std::string &name, int grade)
	: _name(name), _grade(grade) {
		_validateGrade(grade);
	}

inline const std::string &Bureaucrat::getName() const {
	return _name;
}

inline int Bureaucrat::getGrade() const {
	return _grade;
}

inline void Bureaucrat::_validateGrade(int grade) const {
	if (grade < _minGrade) {
		throw GradeTooHighException();
	} else if (grade > _maxGrade) {
		throw GradeTooLowException();
	}
}

inline void Bureaucrat::incrementGrade() {
	_validateGrade(_grade - 1);
	--_grade;
}

inline void Bureaucrat::decrementGrade() {
	_validateGrade(_grade + 1);
	++_grade;
}

const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
    return "Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
    return "Grade too low!";
}

void Bureaucrat::signForm(Form& form) const {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	} catch (const std::exception &e) {
		std::cout << _name << " couldn't sign " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}
