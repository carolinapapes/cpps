/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 17:18:26 by capapes           #+#    #+#             */
/*   Updated: 2026/01/12 00:57:53 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cctype>


// ------------------------------------------------------------------------------------- Start date validator
// Date validator for format YYYY-MM-DD

static bool isAllDigits(const std::string& s) {
	for (std::string::size_type i = 0; i < s.size(); ++i) {
		if (!std::isdigit(static_cast<unsigned char>(s[i])))
			return false;
	}
	return !s.empty();
}

static bool isLeap(int y) {
	if (y % 400 == 0) return true;
	if (y % 100 == 0) return false;
	return (y % 4 == 0);
}

bool BitcoinExchange::isValidDate(const std::string& date, std::string& out) {	
	if (date.size() != 10) return false;
	if (date[4] != '-' || date[7] != '-') return false;

	std::string ys = date.substr(0, 4);
	std::string ms = date.substr(5, 2);
	std::string ds = date.substr(8, 2);

	if (!isAllDigits(ys) || !isAllDigits(ms) || !isAllDigits(ds)) return false;

	int y = std::atoi(ys.c_str());
	int m = std::atoi(ms.c_str());
	int d = std::atoi(ds.c_str());

	if (m < 1 || m > 12) return false;
	if (d < 1) return false;

	int mdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int maxd = mdays[m - 1];
	if (m == 2 && isLeap(y)) maxd = 29;

	out = date;
	return d <= maxd;
}

// ------------------------------------------------------------------------------------- End date validator
// ------------------------------------------------------------------------------------- Start trim function

std::string BitcoinExchange::trim(const std::string& s) {
	std::string::size_type b = 0;
	while (b < s.size() && std::isspace(static_cast<unsigned char>(s[b]))) b++;
	std::string::size_type e = s.size();
	while (e > b && std::isspace(static_cast<unsigned char>(s[e - 1]))) e--;
	return s.substr(b, e - b);
}

// ------------------------------------------------------------------------------------- End trim function
// ------------------------------------------------------------------------------------- Start Othodox canonical form

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _rates(other._rates) {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) _rates = other._rates;
	return *this;
}
BitcoinExchange::~BitcoinExchange() {}

// ------------------------------------------------------------------------------------- End Othodox canonical form

bool BitcoinExchange::parseValue(const std::string& token, double& out) {
	char* end = 0;
	if (token.empty()) return false;

	out = std::strtod(token.c_str(), &end);
	if (end == token.c_str() || *end != '\0') return false;
	return true;
}


double BitcoinExchange::getRateForDateOrClosestLower(const std::string& date) const {
	std::map<std::string, double>::const_iterator it = _rates.find(date);
	if (it != _rates.end())
		return it->second;

	it = _rates.lower_bound(date);
	if (it == _rates.begin())
		throw std::runtime_error("Error: bad input => " + date);

	--it;
	return it->second;
}

void BitcoinExchange::errMessage(eMessageType type, const std::string& line) const
{	
	switch (type)
	{
		case ERR_TOO_LARGE:
			std::cout << "Error: too large a number." << std::endl;
			return;
		case ERR_NEGATIVE:
			std::cout << "Error: not a positive number." << std::endl;
			return;
		case ERR:
		default:
			std::cout << "Error: bad input => " << line << std::endl;
			return;
	}
}

eMessageType BitcoinExchange::checkLine(const std::string& line,
                                        bool isDB,
                                        std::string& date,
                                        double& value) const
{
	const char sep = isDB ? ',' : '|';
	const std::string::size_type pos = line.find(sep);

	if (line.empty() || pos == std::string::npos)
		return ERR;

	const std::string dateToken  = trim(line.substr(0, pos));
	const std::string valueToken = trim(line.substr(pos + 1));

	if (!isValidDate(dateToken, date) ||!parseValue(valueToken, value))
		return ERR;

	if (!isDB && value < 0.0)
		return ERR_NEGATIVE;

	if (!isDB && value > 1000.0)
		return ERR_TOO_LARGE;

	return ERR_NONE;
}

void BitcoinExchange::processLine(const std::string& line, bool isDB)
{
	std::string date;
	double value;

	const eMessageType err = checkLine(line, isDB, date, value);
	if (err)
	{
		errMessage(err, line);
		return ;
	}

	if (isDB)
	{
		_rates[date] = value;
		return;
	}

	try {
		const double rate = getRateForDateOrClosestLower(date);
		std::cout << date << " => " << value << " = " << value * rate << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}


void BitcoinExchange::processFile(const std::string& fileName, bool isDB)
{
	std::ifstream file(fileName.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");

	std::string line;

	if (!std::getline(file, line))
		throw std::runtime_error("Error: bad file.");

	if (isDB && trim(line) != "date,exchange_rate")
		throw std::runtime_error("Error: bad database header.");

	if (!isDB && trim(line) != "date | value")
		processLine(line, false);

	while (std::getline(file, line))
		processLine(line, isDB);
}

void BitcoinExchange::loadDatabase(const std::string& csvPath) {
	processFile(csvPath, true);
	if (_rates.empty())
		throw std::runtime_error("Error: empty database.");
}


