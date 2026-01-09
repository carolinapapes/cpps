/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:06:08 by capapes           #+#    #+#             */
/*   Updated: 2026/01/06 16:54:20 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

// ========================================================
// Orthodox canonical form
// ========================================================

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", _signGrade, _executeGrade)
    , _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other)
    , _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
    if (this != &other) {
       	AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

// ========================================================
// Specific constructor
// ========================================================

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", _signGrade, _executeGrade)
    , _target(target) {}


// ========================================================
// Virtual methods
// ========================================================
void RobotomyRequestForm::performAction() const {
    _seedOnce();

    std::cout << "Brrrr... Bzzzz... Vrrrr..." << std::endl;

    if (std::rand() % 2) {
        std::cout << _target << " has been robotomized successfully." << std::endl;
    } else {
        std::cout << "Robotomy failed on " << _target << "." << std::endl;
    }
}

// ========================================================
// Private Methods
// ========================================================
void RobotomyRequestForm::_seedOnce() {
    static bool seeded = false;

    if (!seeded) {
        std::srand(std::time(NULL));
        seeded = true;
    }
}
