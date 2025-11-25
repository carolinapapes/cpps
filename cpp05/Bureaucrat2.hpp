/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:12:12 by capapes           #+#    #+#             */
/*   Updated: 2025/07/11 14:15:46 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>

class Bureaucrat {
public:
	Bureaucrat(const std::string &name, int grade);	
	~Bureaucrat() = default;
	Bureaucrat(const Bureaucrat &other) = default;
	Bureaucrat &operator=(const Bureaucrat &other) = default;
	const std::string &getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();

	class GradeTooHighException : public std::exception {
	public:
		const char *what() const noexcept override {
			return "Grade too high!";
		}
	};
	class GradeTooLowException : public std::exception {
	public:
		const char *what() const noexcept override {
			return "Grade too low!";
		}
	};
private:
	const std::string _name;
	int _grade;
	static const int _minGrade = 1;
	static const int _maxGrade = 150;
	void validateGrade(int grade) const;
};


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