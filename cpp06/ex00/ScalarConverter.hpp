/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:25:18 by capapes           #+#    #+#             */
/*   Updated: 2026/01/07 16:20:44 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

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

#endif
