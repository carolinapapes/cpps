/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:03:33 by capapes           #+#    #+#             */
/*   Updated: 2025/11/25 18:23:35 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", signGrade, executeGrade), target(target) {}

void PresidentialPardonForm::performAction() const {
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}		