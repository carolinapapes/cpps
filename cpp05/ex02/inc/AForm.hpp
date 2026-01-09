/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:43:54 by capapes           #+#    #+#             */
/*   Updated: 2026/01/06 16:37:38 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

// ========================================================
// Class definition
// ========================================================

class Bureaucrat;

class AForm
{
    public:
        // Orthodox Canonical Form
        AForm();
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        // Specific Constructor
        AForm(std::string name, int gradeToSign, int gradeToExecute);

        // Getters
        const std::string& getName() const;
        int                getGradeToSign() const;
        int                getGradeToExecute() const;
        bool               getIsSigned() const;

        // Methods
        void beSigned(const Bureaucrat& bureaucrat);
        void execute(const Bureaucrat& executor) const;


    protected:
        // Exceptions
        class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
        };

        // Virtual methods
        virtual void performAction() const = 0;

    private:
        // Attributes
        const std::string _name;
        bool              _isSigned;
        const int         _gradeToSign;
        const int         _gradeToExecute;
};


// ========================================================
// Stream output
// ========================================================

std::ostream& operator<<(std::ostream& os, const AForm& form);
