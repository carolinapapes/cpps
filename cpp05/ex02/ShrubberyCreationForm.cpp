/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:06:51 by capapes           #+#    #+#             */
/*   Updated: 2025/12/05 10:19:54 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", _signGrade, _executeGrade), _target(target) {}
	
void ShrubberyCreationForm::performAction() const {
	std::ofstream outfile(_target + "_shrubbery");
	if (!outfile) {
		std::cerr << "Error creating file: " << _target + "_shrubbery" << std::endl;
		return;
	}
	outfile << 	"      ..-***+:.     "
				"  .:++=+==*==++-..  "
				"  .+============*+-. "
				".++=*+============+= "
				".*======+===++=====- "
				" .=++====+*====+=+:. "
				"  .====+**-*=+==+-   "
				"   .:=-:.*+=.....    "
				"        .=+=         "
				"        .++=         "
				"        .*++..       "
				"      .:+****=.      "
				"      ........       ";

	outfile.close();
} 