/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:06:51 by capapes           #+#    #+#             */
/*   Updated: 2025/12/04 16:48:10 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", _signGrade, _executeGrade), target(target) {}
	
void ShrubberyCreationForm::performAction() const {
	std::ofstream outfile(target + "_shrubbery");
	if (!outfile) {
		std::cerr << "Error creating file: " << target + "_shrubbery" << std::endl;
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