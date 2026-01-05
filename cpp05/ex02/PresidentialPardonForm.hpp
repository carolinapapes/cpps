/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:59:04 by capapes           #+#    #+#             */
/*   Updated: 2025/12/05 10:19:02 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		int const 	_signGrade = 25;
		int const 	_executeGrade = 5;
		std::string _target;

	public: 
	// Orthodox canonical form
	PresidentialPardonForm(const std::string &target);
	~PresidentialPardonForm() = default;
	PresidentialPardonForm(const PresidentialPardonForm &other) = default;
	PresidentialPardonForm &operator=(const PresidentialPardonForm &other) = default;
	// Methods
	void performAction() const override;
	private:
};	
