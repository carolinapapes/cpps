/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:03:33 by capapes           #+#    #+#             */
/*   Updated: 2025/12/05 10:19:09 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", _signGrade, _executeGrade), _target(target) {}

void PresidentialPardonForm::performAction() const {
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}		