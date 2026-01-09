/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:25:18 by capapes           #+#    #+#             */
/*   Updated: 2026/01/09 15:48:38 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class ScalarConverter {
public:
	static void convert(std::string const &literal);

private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &);
	ScalarConverter &operator=(ScalarConverter const &);
	~ScalarConverter();
};


