/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:01:29 by capapes           #+#    #+#             */
/*   Updated: 2026/01/05 20:49:16 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
    const int _signGrade = 145;
    const int _executeGrade = 137;

    std::string _target;

public:
    // Orthodox Canonical Form
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();

    // Specific constructor
    ShrubberyCreationForm(const std::string& target);

    // Methods
    void performAction() const;
};