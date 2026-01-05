/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:59:39 by capapes           #+#    #+#             */
/*   Updated: 2025/12/04 16:48:34 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		int const	_signGrade = 72;
		int const 	_executeGrade = 45;
		std::string _target;
	public: 
	// Orthodox canonical form
	RobotomyRequestForm(const std::string &target);
	~RobotomyRequestForm() = default;
	RobotomyRequestForm(const RobotomyRequestForm &other) = default;
	RobotomyRequestForm &operator=(const RobotomyRequestForm &other) = default;
	// Methods
	void performAction() const override;

};
