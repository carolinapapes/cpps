/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:18:04 by capapes           #+#    #+#             */
/*   Updated: 2025/07/11 14:20:53 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>

#include "Bureaucrat.hpp"

class Form {
public:
	Form(const std::string &name, int signGrade, int execGrade);
	~Form() = default;
	Form(const Form &other) = default;
	Form &operator=(const Form &other) = default;
	const std::string &getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool isSigned() const;
	void beSigned(const Bureaucrat &bureaucrat);
	class GradeTooHighException : public std::exception {
	public:
		const char *what() const noexcept override {
			return "Grade too high for form!";
		}
	};
	class GradeTooLowException : public std::exception {
	public:
		const char *what() const noexcept override {
			return "Grade too low for form!";
		}
	};
	private:
		const std::string _name;
		const int _signGrade;
		const int _execGrade;
		bool _isSigned;
		void validateGrade(int grade) const;
};
