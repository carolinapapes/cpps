/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:55:52 by capapes           #+#    #+#             */
/*   Updated: 2025/11/25 14:46:55 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

inline Bureaucrat::Bureaucrat(const std::string &name, int grade)
	: _name(name), _grade(grade) {
		validateGrade(grade);
	}

inline const std::string &Bureaucrat::getName() const {
	return _name;
}

inline int Bureaucrat::getGrade() const {
	return _grade;
}

inline void Bureaucrat::validateGrade(int grade) const {
	if (grade < _minGrade) {
		throw GradeTooHighException();
	} else if (grade > _maxGrade) {
		throw GradeTooLowException();
	}
}

const char *Bureaucrat::GradeTooHighException::what() const noexcept
{
    return "Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept
{
    return "Grade too low!";
}
