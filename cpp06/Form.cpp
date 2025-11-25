/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:21:36 by capapes           #+#    #+#             */
/*   Updated: 2025/07/14 15:09:27 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

inline Form::Form(const std::string &name, int signGrade, int execGrade)
	: _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false) {
	try {
		validateGrade(signGrade);
		validateGrade(execGrade);
	}
	catch (const GradeTooHighException &e) {
		throw GradeTooHighException();
	} catch (const GradeTooLowException &e) {
		throw GradeTooLowException();
	}
}

inline const std::string &Form::getName() const {
	return _name;
}

inline int Form::getSignGrade() const {
	return _signGrade;
}
inline int Form::getExecGrade() const {
	return _execGrade;
}

inline bool Form::isSigned() const {
	return _isSigned;
}

inline void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _signGrade) {
		throw GradeTooLowException();
	}
	_isSigned = true;
}

inline std::ostream &operator<<(std::ostream &os, const Form &form) {
	os << "Form: " << form.getName() 
	   << ", Sign Grade: " << form.getSignGrade() 
	   << ", Exec Grade: " << form.getExecGrade() 
	   << ", Signed: " << (form.isSigned() ? "Yes" : "No");
	return os;
}
