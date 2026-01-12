/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 01:01:28 by capapes           #+#    #+#             */
/*   Updated: 2026/01/12 01:05:33 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <sstream>
#include <stdexcept>

RPN::RPN() {}
RPN::RPN(const RPN& other) { (void)other; }
RPN& RPN::operator=(const RPN& other) { (void)other; return *this; }
RPN::~RPN() {}

bool RPN::isOperator(const std::string& tok) {
	return tok.size() == 1 && (tok[0] == '+' || tok[0] == '-' || tok[0] == '*' || tok[0] == '/');
}

bool RPN::isSingleDigitNumber(const std::string& tok) {
	return tok.size() == 1 && tok[0] >= '0' && tok[0] <= '9';
}

long RPN::applyOp(long a, long b, const std::string& op) {
	switch (op[0]) {
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/':
			if (b == 0)
				throw std::runtime_error("Error");
			return a / b;
	}
	throw std::runtime_error("Error");
}

long RPN::evaluate(const std::string& expr) const {
	std::istringstream iss(expr);
	std::string tok;

	std::stack<long> st;
	while (iss >> tok) {
		if (isSingleDigitNumber(tok)) {
			st.push(static_cast<long>(tok[0] - '0'));
		}
		else if (isOperator(tok)) {
			if (st.size() < 2)
				throw std::runtime_error("Error");
			long b = st.top(); st.pop();
			long a = st.top(); st.pop();
			st.push(applyOp(a, b, tok));
		}
		else {
			throw std::runtime_error("Error");
		}
	}

	if (st.size() != 1)
		throw std::runtime_error("Error");

	return st.top();
}
