/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 17:18:35 by capapes           #+#    #+#             */
/*   Updated: 2026/01/11 21:49:23 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char** av) {
	if (ac != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

	try {
		BitcoinExchange btc;
		btc.loadDatabase("data.csv");
		btc.processFile(av[1], false);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}

	return 0;
}
