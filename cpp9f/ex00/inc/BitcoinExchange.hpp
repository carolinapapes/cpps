/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 17:18:31 by capapes           #+#    #+#             */
/*   Updated: 2026/01/12 00:54:36 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <map>
#include <string>

enum eMessageType {
	ERR_NONE,
	ERR_ONE,
	ERR_TWO,
	ERR_TOO_LARGE,
	ERR_NEGATIVE,
	ERR
};


class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void loadDatabase(const std::string& csvPath);
		void processFile(const std::string& fileName, bool isDB);

	private:
		// container
		std::map<std::string, double> _rates;
		// helper fns
		static std::string 	trim(const std::string& s);
		static bool 		isValidDate(const std::string& token, std::string& out);
		static bool 		parseValue(const std::string& token, double& out);
		void 				errMessage(eMessageType type, const std::string& line) const;
		double 				getRateForDateOrClosestLower(const std::string& date) const;
		
		// main fns
		void 				processLine(const std::string& line, bool isDB);
		eMessageType 		checkLine(	const std::string&	line,
										bool 				isDB,
										std::string& 		date,
										double& 			value) const;
};