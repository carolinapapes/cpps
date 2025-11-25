/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:51:24 by capapes           #+#    #+#             */
/*   Updated: 2025/11/25 13:10:39 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>

class Bureaucrat {
	public:
		// Orthodox canonical form
		Bureaucrat(const std::string &name, int grade);	
		~Bureaucrat() = default;
		Bureaucrat(const Bureaucrat &other) = default;
		Bureaucrat &operator=(const Bureaucrat &other) = default;

		// Methods
		const std::string 	&getName() const;
		int 				getGrade() const;
		void				incrementGrade();
		void				decrementGrade();

		class GradeTooHighException : public std::exception {
			public:
				const char *what() const noexcept override;
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const noexcept override;
		};

	private:
		const std::string 	_name;
		int 				_grade;
		static const int 	_minGrade = 1;
		static const int 	_maxGrade = 150;

		// Methods
		void 				validateGrade(int grade) const;
};

inline std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}