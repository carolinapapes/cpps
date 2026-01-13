/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:17:17 by capapes           #+#    #+#             */
/*   Updated: 2026/01/11 16:14:32 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <stack>
#include "MutantStack.hpp"

// Colors
#define RESET   "\033[0m"
#define WHITE   "\033[37m"   // White
#define GRAY    "\033[90m"   // Gray (bright black)

int main()
{
    MutantStack<int> mstack;
    std::list<int> lst;

    // push 5, 17
    mstack.push(5);
    mstack.push(17);

    lst.push_back(5);
    lst.push_back(17);

	// print
    std::cout << WHITE << "Mutant top:\t";
    std::cout << WHITE << mstack.top() << RESET << std::endl;
   

    std::cout << GRAY << "List back:\t";
    std::cout << GRAY << lst.back() << RESET << std::endl;
	  std::cout << std::endl;

    // pop    
	mstack.pop();
    lst.pop_back();

    // size
	std::cout << WHITE << "Mutant size:\t";
    std::cout << WHITE << mstack.size() << RESET << std::endl;

    std::cout << GRAY << "List size:\t";
    std::cout << GRAY << lst.size() << RESET << std::endl;
    std::cout << std::endl;

    // push more values
	mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    // iterate MutantStack
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    std::cout << WHITE << "Mutant iter content:\t";
    while (it != ite)
    {
        std::cout << WHITE << *it << RESET << "\t";
        ++it;
    }
    std::cout << std::endl;

    // iterate list
    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();

    std::cout << GRAY << "List iter content:\t";
    while (lit != lite)
    {
        std::cout << GRAY << *lit << RESET << "\t";
        ++lit;
    }
    std::cout << std::endl;

    // compatibility check
    std::stack<int> s(mstack);

    return 0;
}
