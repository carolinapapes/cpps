/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:56:25 by capapes           #+#    #+#             */
/*   Updated: 2026/01/05 20:58:47 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Orthodox Canonical Form

AForm::AForm()
    : _name("Default")
    , _isSigned(false)
    , _gradeToSign(150)
    , _gradeToExecute(150)
{
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
    : _name(name)
    , _isSigned(false)
    , _gradeToSign(gradeToSign)
    , _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : _name(other._name)
    , _isSigned(other._isSigned)
    , _gradeToSign(other._gradeToSign)
    , _gradeToExecute(other._gradeToExecute)
{
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm()
{
}

// Getters
const std::string& AForm::getName() const
{
    return _name;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

bool AForm::getIsSigned() const
{
    return _isSigned;
}

// Actions
void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();

    _isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const
{
    if (!_isSigned)
        throw GradeTooLowException();

    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();

    performAction();
}

// Exceptions
const char* AForm::GradeTooHighException::what() const throw()
{
    return "Form grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Form grade too low!";
}

//
// Stream output
//

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << "Form: " << form.getName()
       << "\n  Signed: " << (form.getIsSigned() ? "yes" : "no")
       << "\n  Grade to sign: " << form.getGradeToSign()
       << "\n  Grade to execute: " << form.getGradeToExecute();

    return os;
}