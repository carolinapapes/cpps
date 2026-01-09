/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:51:24 by capapes           #+#    #+#             */
/*   Updated: 2026/01/06 17:11:41 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

// ========================================================
// Class definition
// ========================================================

class AForm;

class Bureaucrat {
	public:
		// Orthodox canonical form
		Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		// Specific constructor
		Bureaucrat(const std::string &name, int grade);

		// Getters
		const std::string 	&getName() const;
		int 				getGrade() const;
		
		// Methods
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(AForm& form) const;

		// Exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

	private:
		// Attributes
		const std::string 	_name;
		int 				_grade;
		static const int 	_minGrade = 1;
		static const int 	_maxGrade = 150;

		// Methods
		void 				_validateGrade(int grade) const;
};


// ========================================================
// Stream output
// ========================================================

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);