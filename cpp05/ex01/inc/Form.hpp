/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:43:54 by capapes           #+#    #+#             */
/*   Updated: 2026/01/06 16:36:35 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"


// ========================================================
// Class definition
// ========================================================


class Form
{
	public:
		// Orthodox canonical form
		Form();
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		// Specific constructor
		Form(std::string name, int gradeToSign, int gradeToExecute);

		// Getters
		const std::string& 	getName() 			const;
		bool				getIsSigned() 		const;
		int 				getGradeToSign() 	const;
		int 				getGradeToExecute() const;

		// Exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		// Methods
		void				beSigned(const Bureaucrat& bureaucrat);

	private:
		// Attributes
		const std::string 	_name;
		bool 				_isSigned;
		int const 			_gradeToSign;
		int const 			_gradeToExecute;
};

// ========================================================
// Stream output
// ========================================================

std::ostream &operator<<(std::ostream &os, const Form &form);