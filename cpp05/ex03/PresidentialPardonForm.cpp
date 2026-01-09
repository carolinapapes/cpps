/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:03:33 by capapes           #+#    #+#             */
/*   Updated: 2026/01/06 16:52:00 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// ========================================================
// Orthodox canonical form
// ========================================================

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", _signGrade, _executeGrade)
    , _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other)
    , _target(other._target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

// ========================================================
// Specific constructor
// ========================================================
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", _signGrade, _executeGrade)
    , _target(target) {}


// ========================================================
// Virtual Methods
// ========================================================
void PresidentialPardonForm::performAction() const
{
    std::cout << _target
              << " has been pardoned by Zaphod Beeblebrox."
              << std::endl;
}	