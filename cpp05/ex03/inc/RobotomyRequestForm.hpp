/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:59:39 by capapes           #+#    #+#             */
/*   Updated: 2026/01/06 16:52:21 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    public:
        // Orthodox Canonical Form
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();

        // Specific constructor
        RobotomyRequestForm(const std::string& target);

        // Virtual Methods
        void performAction() const;

    private:
        // Attributes
        enum {
            _signGrade = 72,
            _executeGrade = 45
        };
        std::string _target;

        // Private Methods
        static void _seedOnce();
};
