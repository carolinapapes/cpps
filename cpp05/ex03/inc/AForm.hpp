/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:43:54 by capapes           #+#    #+#             */
/*   Updated: 2026/01/05 20:57:27 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    const std::string _name;
    bool              _isSigned;
    const int         _gradeToSign;
    const int         _gradeToExecute;

protected:
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

public:
    // Orthodox Canonical Form
    AForm();
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    // Constructor
    AForm(std::string name, int gradeToSign, int gradeToExecute);

    // Getters
    const std::string& getName() const;
    int                getGradeToSign() const;
    int                getGradeToExecute() const;
    bool               getIsSigned() const;

    // Actions
    void beSigned(const Bureaucrat& bureaucrat);
    void execute(const Bureaucrat& executor) const;

protected:
    virtual void performAction() const = 0;
};

// Stream output
std::ostream& operator<<(std::ostream& os, const AForm& form);
