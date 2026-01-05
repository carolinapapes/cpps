/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:26:48 by capapes           #+#    #+#             */
/*   Updated: 2025/12/05 09:37:42 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#define SHRUBBERY_CREATION_FORM "shrubbery creation"
#define ROBOTOMY_REQUEST_FORM "robotomy request"
#define PRESIDENTIAL_PARDON_FORM "presidential pardon"
#define FORM_COUNT 3

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const {
	std::string formNames[FORM_COUNT] = {
		SHRUBBERY_CREATION_FORM,
		ROBOTOMY_REQUEST_FORM,
		PRESIDENTIAL_PARDON_FORM
	};

	AForm *(*formCreators[FORM_COUNT])(const std::string &target) = {
		[](const std::string &target) { return new ShrubberyCreationForm(target); },
		[](const std::string &target) { return new RobotomyRequestForm(target); },
		[](const std::string &target) { return new PresidentialPardonForm(target); }
	};

	for (size_t i = 0; i < 3; ++i) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << " form." << std::endl;
			return formCreators[i](target);
		}
	}
	std::cout << "Intern could not find the form: " << formName << std::endl;
	return nullptr;
}