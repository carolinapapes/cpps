/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:01:29 by capapes           #+#    #+#             */
/*   Updated: 2026/01/06 17:05:23 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
    public:
        // Orthodox Canonical Form
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();

        // Specific constructor
        ShrubberyCreationForm(const std::string& target);

        // Virtual Methods
        void performAction() const;

    private:
        // Methods
        enum {
            _signGrade = 145,
            _executeGrade = 137
        };
        std::string _target;

};