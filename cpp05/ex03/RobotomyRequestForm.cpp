/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:06:08 by capapes           #+#    #+#             */
/*   Updated: 2025/11/25 18:23:20 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", signGrade, executeGrade), target(target) {}
	
void RobotomyRequestForm::performAction() const {
	std::srand(std::time(nullptr));
	std::cout << "Brrrr... Bzzzz... Vrrrr..." << std::endl;
	if (std::rand() % 2) {
		std::cout << target << " has been robotomized successfully." << std::endl;
	} else {
		std::cout << "Robotomy failed on " << target << "." << std::endl;
	}
}