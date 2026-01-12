/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 01:01:23 by capapes           #+#    #+#             */
/*   Updated: 2026/01/12 01:01:55 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <stack>

class RPN {
public:
	RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();

	// Evaluates an RPN expression like: "8 9 * 9 -"
	// Throws on error.
	long evaluate(const std::string& expr) const;

private:
	static bool isOperator(const std::string& tok);
	static bool isSingleDigitNumber(const std::string& tok);
	static long applyOp(long a, long b, const std::string& op);
};

