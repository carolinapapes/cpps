/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:34:01 by capapes           #+#    #+#             */
/*   Updated: 2026/01/14 11:49:19 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <vector>
#include <deque>
#include <string>

struct MultiLevelPairsDq{
    std::deque<MultiLevelPairsDq> levels;
    int lead;
	int level;
};

struct MultiLevelPairsVc{
    std::vector<MultiLevelPairsVc> levels;
    int lead;
	int level;
};

class PmergeMe {
public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void run(int ac, char** av);

private:
	std::deque<MultiLevelPairsDq>  _deq;
	std::vector<MultiLevelPairsVc> _vec;

	static bool isPositiveIntToken(const std::string& s);
	static long toLong(const std::string& s);
	void parseArgs(int ac, char** av);
	
	// timing
	static double nowMicros();

	// Ford–Johnson for deque
	static std::deque<MultiLevelPairsDq>fordJohnsonDeque(std::deque< MultiLevelPairsDq> input);
	static std::vector< MultiLevelPairsVc>fordJohnsonVector(std::vector<MultiLevelPairsVc> nodes);
};

