/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09                                    #+#    #+#       */
/*   Updated: 2026/01/09                                    ###   ########.fr */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

static void print_data(Data const &d)
{
	std::cout << "Data {\n";
	std::cout << "  id: " << d.id << "\n";
	std::cout << "  name: " << d.name << "\n";
	std::cout << "  score: " << d.score << "\n";
	std::cout << "}\n";
}

int main(void)
{
	Data d;
	d.id = 42;
	d.name = "capapes";
	d.score = 99.5;

	std::cout << "Original object:\n";
	print_data(d);

	Data* originalPtr = &d;
	uintptr_t raw = Serializer::serialize(originalPtr);
	Data* recoveredPtr = Serializer::deserialize(raw);

	std::cout << "\nRaw: " << raw << "\n";
	std::cout << "\nPointers:\n";
	std::cout << "originalPtr : " << originalPtr << "\n";
	std::cout << "recoveredPtr: " << recoveredPtr << "\n";

	std::cout << "\nCheck:\n";
	if (recoveredPtr == originalPtr)
		std::cout << "OK: pointers are equal\n";
	else
		std::cout << "KO: pointers differ\n";

	std::cout << "\nRecovered object:\n";
	print_data(*recoveredPtr);

	return 0;
}
