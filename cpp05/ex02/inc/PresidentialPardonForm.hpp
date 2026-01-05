/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:59:04 by capapes           #+#    #+#             */
/*   Updated: 2026/01/05 20:52:45 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AForm.hpp"

#include <string>

class PresidentialPardonForm : public AForm {
private:
    enum {
        _signGrade = 25,
        _executeGrade = 5
    };

    std::string _target;

public:
    // Orthodox Canonical Form
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    ~PresidentialPardonForm();

    // Specific constructor
    PresidentialPardonForm(const std::string& target);

    // Methods
    void performAction() const;
};
