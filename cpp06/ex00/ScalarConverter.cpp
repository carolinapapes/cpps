/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 16:25:15 by capapes           #+#    #+#             */
/*   Updated: 2026/01/09 17:02:44 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <cmath>

// ===================== Types =====================

enum LiteralType {
	TYPE_CHAR = 0,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_PSEUDO_FLOAT,
	TYPE_PSEUDO_DOUBLE,
	TYPE_INVALID,
	TYPE_COUNT
};

enum SpecialKind {
	SK_NONE = 0,
	SK_NAN,
	SK_POS_INF,
	SK_NEG_INF,
	SK_COUNT
};

struct TypeRule {
	bool (*matches)(std::string const &);
	LiteralType type;
};

typedef double (*ConvertFn)(std::string const &, bool &ok);
typedef void (*PrintFn)(double);

#define MINCHAR  static_cast<double>(std::numeric_limits<char>::min())
#define MAXCHAR  static_cast<double>(std::numeric_limits<char>::max())
#define MININT   static_cast<double>(std::numeric_limits<int>::min())
#define MAXINT   static_cast<double>(std::numeric_limits<int>::max())

// ===================== Low-level helpers =====================

static bool is_nan(double x) { return x != x; }

static bool is_inf(double x) {
	double inf = std::numeric_limits<double>::infinity();
	return (x == inf || x == -inf);
}

static SpecialKind special_kind(double x) {
	if (is_nan(x)) return SK_NAN;
	if (is_inf(x)) return (x < 0 ? SK_NEG_INF : SK_POS_INF);
	return SK_NONE;
}

static bool is_integral(double x) {
	if (is_nan(x) || is_inf(x)) return false;
	double ip;
	return std::modf(x, &ip) == 0.0;
}

static bool parse_int(std::string const &s, long &out) {
	char *end = 0;
	out = std::strtol(s.c_str(), &end, 10);
	return (end != s.c_str() && *end == '\0');
}

static bool parse_double(std::string const &s, double &out) {
	char *end = 0;
	out = std::strtod(s.c_str(), &end);
	return (end != s.c_str() && *end == '\0');
}

// ===================== Matchers (for detect_type) =====================

static bool match_pseudo_float(std::string const &s) {
	return (s == "nanf" || s == "+inff" || s == "-inff");
}

static bool match_pseudo_double(std::string const &s) {
	return (s == "nan" || s == "+inf" || s == "-inf");
}

static bool match_char(std::string const &s) {
	if (s.size() == 3 && s[0] == '\'' && s[2] == '\'')
		return true;
	if (s.size() == 1 && !std::isdigit(static_cast<unsigned char>(s[0])))
		return true;
	return false;
}

static bool match_int(std::string const &s) {
	long tmp;
	return parse_int(s, tmp);
}

static bool match_float(std::string const &s) {
	if (s.size() <= 1 || s[s.size() - 1] != 'f')
		return false;
	double tmp;
	return parse_double(s.substr(0, s.size() - 1), tmp);
}

static bool match_double(std::string const &s) {
	double tmp;
	return parse_double(s, tmp);
}

// ===================== Type detection =====================
static LiteralType detect_type(std::string const &s) {
	static TypeRule const rules[] = {
		{ &match_pseudo_float,  TYPE_PSEUDO_FLOAT  },
		{ &match_pseudo_double, TYPE_PSEUDO_DOUBLE },
		{ &match_char,          TYPE_CHAR          },
		{ &match_int,           TYPE_INT           },
		{ &match_float,         TYPE_FLOAT         },
		{ &match_double,        TYPE_DOUBLE        }
	};

	for (size_t i = 0; i < sizeof(rules) / sizeof(rules[0]); ++i) {
		if (rules[i].matches(s))
			return rules[i].type;
	}
	return TYPE_INVALID;
}

// ===================== Converters (LiteralType -> double) =====================

static double conv_invalid(std::string const &, bool &ok) {
	ok = false;
	return 0.0;
}

static double conv_pseudo(std::string const &s, bool &ok) {
	ok = true;
	if (s[0] == '-') return -std::numeric_limits<double>::infinity();
	if (s[0] == '+') return  std::numeric_limits<double>::infinity();
	return std::numeric_limits<double>::quiet_NaN(); // nan/nanf
}

static double conv_char(std::string const &s, bool &ok) {
	ok = true;
	char c = (s.size() == 3 && s[0] == '\'') ? s[1] : s[0];
	return static_cast<double>(c);
}

static double conv_int(std::string const &s, bool &ok) {
	long li = 0;
	ok = parse_int(s, li);
	if (!ok) return 0.0;
	return static_cast<double>(li);
}

static double conv_float(std::string const &s, bool &ok) {
	double d = 0.0;
	ok = parse_double(s.substr(0, s.size() - 1), d); // strip 'f'
	if (!ok) return 0.0;
	return d;
}

static double conv_double(std::string const &s, bool &ok) {
	double d = 0.0;
	ok = parse_double(s, d);
	if (!ok) return 0.0;
	return d;
}

static double to_value(std::string const &literal, LiteralType type, bool &ok) {
	static ConvertFn const converters[TYPE_COUNT] = {
		&conv_char,
		&conv_int,
		&conv_float,
		&conv_double,
		&conv_pseudo,
		&conv_pseudo,
		&conv_invalid
	};

	size_t idx = static_cast<size_t>(type);
	if (idx >= TYPE_COUNT)
		return conv_invalid(literal, ok);
	return converters[idx](literal, ok);
}

// ===================== Special strings table =====================

struct SpecialStrings {
	char const *dbl;
	char const *flt;
};

static SpecialStrings const g_special_strs[SK_COUNT] = {
	{ 0,      0      },
	{ "nan",  "nanf"  },
	{ "+inf", "+inff" },
	{ "-inf", "-inff" }
};

static void print_sk(double x, int type) {
	switch (type) {
		case TYPE_CHAR:
		case TYPE_INT:
			std::cout << "impossible\n";
			break;
		case TYPE_FLOAT:
			std::cout << g_special_strs[special_kind(x)].flt << "\n";
			break;
		case TYPE_DOUBLE:
			std::cout << g_special_strs[special_kind(x)].dbl << "\n";
			break;
	}
}

// ===================== Printers (double -> output) =====================

static void print_char(double x){
	if ( x < MINCHAR || x > MAXCHAR ) {
		std::cout << "impossible\n";
		return;
	}

	char c = static_cast<char>(x);
	!std::isprint(static_cast<unsigned char>(c)) ? 
		std::cout << "Non displayable\n" :
		std::cout << "'" << c << "'\n";
}

static void print_int(double x){
	if ( x < MININT || x > MAXINT ) {
		std::cout << "impossible\n";
		return;
	}
	std::cout << static_cast<int>(x) << "\n";
}

static void print_double(double x){
	std::ios::fmtflags oldFlags = std::cout.flags();
	std::streamsize    oldPrec  = std::cout.precision();

	if (is_integral(x))
		std::cout << std::fixed << std::setprecision(1) << x << "\n";
	else
		std::cout << x << "\n";

	std::cout.flags(oldFlags);
	std::cout.precision(oldPrec);
}

static void print_float(double x){
	std::ios::fmtflags oldFlags = std::cout.flags();
	std::streamsize    oldPrec  = std::cout.precision();

	float f = static_cast<float>(x);

	if (is_integral(x))
	{
		std::cout << std::fixed << std::setprecision(1) << f << "f\n";
	}
	else
	{
		std::cout.unsetf(std::ios::floatfield);
		std::cout << f << "f\n";
	}

	std::cout.flags(oldFlags);
	std::cout.precision(oldPrec);
}

// ==================== High-level printers =====================
static void printer(char const *type_name, int type, double x, PrintFn print_type) {
	std::cout << type_name << ": ";
	special_kind(x) != SK_NONE ?
		print_sk(x, type) :
		print_type(x);
}

static void print_all(double value) {
	printer("char", TYPE_CHAR, value, print_char);
	printer("int", TYPE_INT, value, print_int);
	printer("float", TYPE_FLOAT, value, print_float);
	printer("double", TYPE_DOUBLE, value, print_double);
}

static void print_none() {
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: impossible\n";
	std::cout << "double: impossible\n";
}

// ===================== ScalarConverter orthodox canonical form =====================

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const &) {}
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &) { return *this; }

// ===================== Public API =====================

void ScalarConverter::convert(std::string const &literal) {
	LiteralType type = detect_type(literal);

	bool ok = false;
	double value = to_value(literal, type, ok);

	!ok ? print_none() : print_all(value);

}
