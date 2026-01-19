/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 01:01:26 by capapes           #+#    #+#             */
/*   Updated: 2026/01/15 11:49:52 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <exception>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    try
    {
        RPN rpn;
        long result = rpn.evaluate(argv[1]);
        std::cout << result << std::endl;
    }
    catch (const std::exception&)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    return 0;
}