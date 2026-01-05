/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:59:39 by capapes           #+#    #+#             */
/*   Updated: 2026/01/05 20:50:12 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
    enum {
        _signGrade = 72,
        _executeGrade = 45
    };

    std::string _target;

    static void _seedOnce(); // helper (C++98)

public:
    // Orthodox Canonical Form
    RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm();

    // Specific constructor
    RobotomyRequestForm(const std::string& target);

    // Methods
    void performAction() const;
};
