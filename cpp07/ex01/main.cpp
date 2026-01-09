/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:56:34 by capapes           #+#    #+#             */
/*   Updated: 2026/01/09 15:56:55 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

static void print_int(int const &x) { std::cout << x << "\n"; }
static void inc_int(int &x) { ++x; }

static void print_str(std::string const &s) { std::cout << s << "\n"; }
static void upper_first(std::string &s)
{
	if (!s.empty() && s[0] >= 'a' && s[0] <= 'z')
		s[0] = static_cast<char>(s[0] - 'a' + 'A');
}

int main(void)
{
	int a[] = {1, 2, 3, 4};
	size_t alen = sizeof(a) / sizeof(a[0]);

	std::cout << "Original int array:\n";
	::iter(a, alen, &print_int);

	::iter(a, alen, &inc_int);
	std::cout << "After inc:\n";
	::iter(a, alen, &print_int);

	std::string s[] = {"hello", "world", "templates"};
	size_t slen = sizeof(s) / sizeof(s[0]);

	std::cout << "\nOriginal string array:\n";
	::iter(s, slen, &print_str);

	::iter(s, slen, &upper_first);
	std::cout << "After upper_first:\n";
	::iter(s, slen, &print_str);

	std::cout << "\nConst array test:\n";
	int const ca[] = {10, 20, 30};
	::iter(ca, sizeof(ca) / sizeof(ca[0]), &print_int);

	return 0;
}
