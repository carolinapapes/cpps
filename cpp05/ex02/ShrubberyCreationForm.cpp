/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:06:51 by capapes           #+#    #+#             */
/*   Updated: 2026/01/05 20:46:41 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", _signGrade, _executeGrade)
    , _target("default")
{
}

// Target constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", _signGrade, _executeGrade)
    , _target(target)
{
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other)
    , _target(other._target)
{
}

// Copy assignment operator
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

// Action
void ShrubberyCreationForm::performAction() const
{
    std::ofstream outfile((_target + "_shrubbery").c_str());
    if (!outfile) {
        std::cerr << "Error creating file: " << _target << "_shrubbery" << std::endl;
        return;
    }

    outfile <<
        "      ..-***+:.     \n"
        "  .:++=+==*==++-..  \n"
        "  .+============*+-. \n"
        ".++=*+============+= \n"
        ".*======+===++=====- \n"
        " .=++====+*====+=+:. \n"
        "  .====+**-*=+==+-   \n"
        "   .:=-:.*+=.....    \n"
        "        .=+=         \n"
        "        .++=         \n"
        "        .*++..       \n"
        "      .:+****=.      \n"
        "      ........       \n";

    outfile.close();
}