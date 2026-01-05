/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:26:01 by capapes           #+#    #+#             */
/*   Updated: 2025/11/25 18:26:38 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	public:
	// Orthodox canonical form
	Intern() = default;
	~Intern() = default;
	Intern(const Intern &other) = default;
	Intern &operator=(const Intern &other) = default;
	// Methods
	AForm *makeForm(const std::string &formName, const std::string &target) const;
};