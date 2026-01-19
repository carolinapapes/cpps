/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:34:53 by capapes           #+#    #+#             */
/*   Updated: 2026/01/12 11:34:53 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char** av)
{
	try {
		PmergeMe p;
		p.run(ac, av);
	} catch (...) {
		std::cerr << "Error" << std::endl;
		return 1;
	}
	return 0;
}
