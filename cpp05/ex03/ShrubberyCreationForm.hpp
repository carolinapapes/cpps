/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:01:29 by capapes           #+#    #+#             */
/*   Updated: 2025/12/05 10:22:09 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		int const 	_signGrade = 145;
		int const 	_executeGrade = 137;
		std::string _target;
	public: 
	// Orthodox canonical form
	ShrubberyCreationForm(const std::string &target);
	~ShrubberyCreationForm() = default;
	ShrubberyCreationForm(const ShrubberyCreationForm &other) = default;
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other) = default;
	// Methods
	void performAction() const override;
	private:
};