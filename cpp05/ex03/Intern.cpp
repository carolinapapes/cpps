/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:26:48 by capapes           #+#    #+#             */
/*   Updated: 2026/01/05 21:06:28 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

#define SHRUBBERY_CREATION_FORM "shrubbery creation"
#define ROBOTOMY_REQUEST_FORM "robotomy request"
#define PRESIDENTIAL_PARDON_FORM "presidential pardon"
#define FORM_COUNT 3

// Creator functions (C++98)
static AForm* createShrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

// Orthodox Canonical Form

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    if (this != &other) {
        // Intern has no data members to copy
    }
    return *this;
}

Intern::~Intern()
{
}

// Method

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
    static const char* formNames[FORM_COUNT] = {
        SHRUBBERY_CREATION_FORM,
        ROBOTOMY_REQUEST_FORM,
        PRESIDENTIAL_PARDON_FORM
    };

    AForm* (*formCreators[FORM_COUNT])(const std::string&) = {
        &createShrubbery,
        &createRobotomy,
        &createPresidential
    };

    for (int i = 0; i < FORM_COUNT; ++i) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << " form." << std::endl;
            return formCreators[i](target);
        }
    }

    std::cout << "Intern could not find the form: " << formName << std::endl;
    return NULL;
}