/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:42:43 by capapes           #+#    #+#             */
/*   Updated: 2026/01/09 17:28:04 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "identify.hpp"
#include <iostream>
#include <cstdlib> // srand, rand
#include <ctime>   // time

int main(void)
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	for (int i =0; i < 10; i++)
	{
		
		Base* p = generate();
		
		std::cout << "identify(Base*): ";
		identify(p);
		
		std::cout << "identify(Base&): ";
		identify(*p);
		
		std::cout << "-----\n";
		delete p;
	}
	return 0;
}