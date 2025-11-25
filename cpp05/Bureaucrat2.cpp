/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:16:26 by capapes           #+#    #+#             */
/*   Updated: 2025/07/11 14:16:42 by capapes          ###   ########.fr       */
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

inline void Bureaucrat::incrementGrade() {
	if (_grade <= _minGrade) {
		throw GradeTooHighException();
	}
	--_grade;
}
inline void Bureaucrat::decrementGrade() {
	if (_grade >= _maxGrade) {
		throw GradeTooLowException();
	}
	++_grade;
}

inline void Bureaucrat::validateGrade(int grade) const {
	if (grade < _minGrade) {
		throw GradeTooHighException();
	} else if (grade > _maxGrade) {
		throw GradeTooLowException();
	}
}

inline std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}