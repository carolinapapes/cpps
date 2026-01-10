/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:59:30 by capapes           #+#    #+#             */
/*   Updated: 2026/01/10 18:12:53 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main()
{
	std::cout << "=== Default constructor ===" << std::endl;
	Array<int> a;
	std::cout << "Size of a: " << a.size() << std::endl;

	std::cout << "\n=== Sized constructor ===" << std::endl;
	Array<int> b(5);
	std::cout << "Size of b: " << b.size() << std::endl;

	for (size_t i = 0; i < b.size(); ++i)
		b[i] = static_cast<int>(i * 10);

	for (size_t i = 0; i < b.size(); ++i)
		std::cout << "b[" << i << "] = " << b[i] << std::endl;

	std::cout << "\n=== Copy constructor ===" << std::endl;
	Array<int> c(b);
	for (size_t i = 0; i < c.size(); ++i)
		std::cout << "c[" << i << "] = " << c[i] << std::endl;

	std::cout << "\n=== Assignment operator ===" << std::endl;
	Array<int> d;
	d = b;
	for (size_t i = 0; i < d.size(); ++i)
		std::cout << "d[" << i << "] = " << d[i] << std::endl;

	std::cout << "\n=== Const access ===" << std::endl;
	const Array<int> e(b);
	for (size_t i = 0; i < e.size(); ++i)
		std::cout << "e[" << i << "] = " << e[i] << std::endl;

	std::cout << "\n=== Out of bounds test ===" << std::endl;
	try
	{
		std::cout << b[10] << std::endl; // should throw
	}
	catch (std::exception &ex)
	{
		std::cout << "Caught exception: " << ex.what() << std::endl;
	}

	std::cout << "\n=== Different type test (std::string) ===" << std::endl;
	Array<std::string> s(3);
	s[0] = "hello";
	s[1] = "array";
	s[2] = "template";

	for (size_t i = 0; i < s.size(); ++i)
		std::cout << "s[" << i << "] = " << s[i] << std::endl;

	return 0;
}
