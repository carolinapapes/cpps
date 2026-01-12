/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:34:01 by capapes           #+#    #+#             */
/*   Updated: 2026/01/12 13:14:47 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <vector>
#include <deque>
#include <string>

struct MultiLevelPairs{
    std::deque<MultiLevelPairs> levels;
    int lead;
};

class PmergeMe {
public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void run(int ac, char** av);

private:
	std::deque<MultiLevelPairs>  _deq;

	// parsing / printing
	void parseArgs(int ac, char** av);
	static bool isPositiveIntToken(const std::string& s);
	static long toLong(const std::string& s);
	static void printSequence(	const std::string& label,
								const std::deque< MultiLevelPairs>& d);

	// timing
	static double nowMicros();

	// Ford–Johnson for deque
	static std::deque<MultiLevelPairs>fordJohnsonDeque(const std::deque< MultiLevelPairs>& input);
	static void mergeSortPairsDeq(std::deque< std::pair<int,int> >& a);
	static void mergePairsDeq(std::deque< std::pair<int,int> >& a,
	                          std::deque< std::pair<int,int> >& tmp,
	                          int l, int m, int r);
	static void mergeSortPairsDeqRec(std::deque< std::pair<int,int> >& a,
	                                std::deque< std::pair<int,int> >& tmp,
	                                int l, int r);
	static size_t lowerBoundDeq(const std::deque<int>& a, int x);
};

