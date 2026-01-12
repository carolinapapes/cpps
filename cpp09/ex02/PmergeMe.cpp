/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:33:38 by capapes           #+#    #+#             */
/*   Updated: 2026/01/12 14:46:15 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <cctype>
#include <sys/time.h>

// ------------------------------------------------------------------------------------- OCF Start
PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& o) : _deq(o._deq) {}
PmergeMe& PmergeMe::operator=(const PmergeMe& o) {
	if (this != &o) { _deq = o._deq; }
	return *this;
}
PmergeMe::~PmergeMe() {}

// ------------------------------------------------------------------------------------- OCF End
// ------------------------------------------------------------------------------------- 
double PmergeMe::nowMicros() {
	timeval tv;
	gettimeofday(&tv, 0);
	return (double)tv.tv_sec * 1000000.0 + (double)tv.tv_usec;
}

void PmergeMe::printSequence(const std::string& label, const std::deque< MultiLevelPairs>& d) {
	std::cout << label;
	const size_t limit = 20;
	for (size_t i = 0; i < d.size() && i < limit; ++i)
			std::cout <<  d[i].lead << std::endl;
	if (d.size() > limit) std::cout << " [...]";
	std::cout << std::endl;
}

// ------------------------------------------------------------------------------------- 
// ------------------------------------------------------------------------------------- Prase Args start


bool PmergeMe::isPositiveIntToken(const std::string& s) {
	if (s.empty()) return false;
	for (size_t i = 0; i < s.size(); ++i) {
		if (!std::isdigit(static_cast<unsigned char>(s[i])))
			return false;
	}
	return true;
}

long PmergeMe::toLong(const std::string& s) {
	std::istringstream iss(s);
	long x;
	iss >> x;
	return iss.fail() ? -1 : x;
}

void PmergeMe::parseArgs(int ac, char** av) {
	_deq.clear();

	for (int i = 1; i < ac; ++i) {
		std::string tok(av[i]);
		if (!isPositiveIntToken(tok))
			throw std::runtime_error("Error");
		long x = toLong(tok);
		if (x <= 0 || x > 2147483647L)
			throw std::runtime_error("Error");
		MultiLevelPairs next;
		next.lead = x;

		_deq.push_back(next);
	}
	if (_deq.empty())
		throw std::runtime_error("Error");
}

// ------------------------------------------------------------------------------------- Prase Args ends
// ------------------------------------------------------------------------------------- 

// Jacobsthal numbers: J(0)=0, J(1)=1, J(n)=J(n-1)+2*J(n-2)
// static size_t jacob(size_t n) {
// 	if (n == 0) return 0;
// 	if (n == 1) return 1;
// 	size_t a = 0, b = 1;
// 	for (size_t i = 2; i <= n; ++i) {
// 		size_t c = b + 2 * a;
// 		a = b; b = c;
// 	}
// 	return b;
// }


size_t PmergeMe::lowerBoundDeq(const std::deque<int>& a, int x) {
	size_t l = 0, r = a.size();
	while (l < r) {
		size_t m = l + (r - l) / 2;
		if (a[m] < x) l = m + 1;
		else r = m;
	}
	return l;
}

/* ---------- merge sort for pair containers (no <algorithm>) ---------- */


void PmergeMe::mergePairsDeq(std::deque< std::pair<int,int> >& a,
                            std::deque< std::pair<int,int> >& tmp,
                            int l, int m, int r)
{
	int i = l, j = m, k = l;
	while (i < m && j < r) {
		if (a[i].second <= a[j].second) tmp[k++] = a[i++];
		else tmp[k++] = a[j++];
	}
	while (i < m) tmp[k++] = a[i++];
	while (j < r) tmp[k++] = a[j++];
	for (int p = l; p < r; ++p) a[p] = tmp[p];
}

void PmergeMe::mergeSortPairsDeqRec(std::deque< std::pair<int,int> >& a,
                                   std::deque< std::pair<int,int> >& tmp,
                                   int l, int r)
{
	if (r - l <= 1) return;
	int m = l + (r - l) / 2;
	mergeSortPairsDeqRec(a, tmp, l, m);
	mergeSortPairsDeqRec(a, tmp, m, r);
	mergePairsDeq(a, tmp, l, m, r);
}

void PmergeMe::mergeSortPairsDeq(std::deque< std::pair<int,int> >& a) {
	std::deque< std::pair<int,int> > tmp;
	tmp.resize(a.size());
	mergeSortPairsDeqRec(a, tmp, 0, (int)a.size());
}

#define GRAY  "\033[90m"
#define BOLD  "\033[1m"
#define RESET "\033[0m"

void printNodeBracket(const MultiLevelPairs& node, bool isLead)
{
    if (node.levels.empty())
    {
		isLead ?
        std::cout << BOLD << node.lead << RESET :
		std::cout << GRAY << node.lead << RESET;
        return;
    }
    std::cout << "[ ";
    printNodeBracket(node.levels[0], isLead && false);
    std::cout << " | ";
    printNodeBracket(node.levels[1], isLead && true);
    std::cout << " ]";
}
bool makePairsOnce(const std::deque<MultiLevelPairs>& input,
                   std::deque<MultiLevelPairs>& pairs,
                   MultiLevelPairs& stray)
{
    pairs.clear();

    for (size_t i = 0; i + 1 < input.size(); i += 2)
    {
        const MultiLevelPairs& left  = input[i];
        const MultiLevelPairs& right = input[i + 1];

        MultiLevelPairs next;
        if (left.lead <= right.lead) {
            next.levels.push_back(left);
            next.levels.push_back(right);
        } else {
            next.levels.push_back(right);
            next.levels.push_back(left);
        }
        next.lead = next.levels.back().lead;

        pairs.push_back(next);
    }
	for (size_t i = 0; i < pairs.size(); i++)
			printNodeBracket(pairs[i], true);

    if (input.size() % 2 == 1) {
        stray = input.back();
		printNodeBracket(stray, true);
		std::cout << std::endl;
        return true;
    }
	std::cout << std::endl;
    return false;
}


MultiLevelPairs buildPairTree(std::deque<MultiLevelPairs> nodes)
{
    if (nodes.empty())
        return MultiLevelPairs();

    while (nodes.size() > 1)
    {
        std::deque<MultiLevelPairs> paired;
        MultiLevelPairs stray;

        bool hasStray = makePairsOnce(nodes, paired, stray);
        if (hasStray)
            paired.push_back(stray);

        if (paired.size() >= nodes.size()) {
            std::cerr << "Error: pairing did not reduce size ("
                      << nodes.size() << " -> " << paired.size() << ")\n";
            break;
        }

        nodes.swap(paired);
    }
	
    return nodes.front();
}

std::deque<MultiLevelPairs> PmergeMe::fordJohnsonDeque(const std::deque< MultiLevelPairs>& input)
{
	if (input.size() <= 1) return input;

	// 1) build pairs (min,max)
	std::deque< MultiLevelPairs> pairs;

	MultiLevelPairs root = buildPairTree(input);

	// // 2) sort pairs by max
	// mergeSortPairsDeq(pairs);

	// // 3) main chain = sorted maxes, pending = mins in that order
	std::deque<MultiLevelPairs> mainc;
	// std::deque<int> pend;
	// for (size_t i = 0; i < pairs.size(); ++i) {
	// 	pend.push_back(pairs[i].first);
	// 	mainc.push_back(pairs[i].second);
	// }
	// if (stray != -1) pend.push_back(stray);

	// // 4) insert pend[0] at beginning, then Jacob order inserts the rest
	// if (!pend.empty()) {
	// 	mainc.push_front(pend[0]);
	// }

	// std::vector<size_t> order = jacobOrder(pend.size());
	// for (size_t oi = 0; oi < order.size(); ++oi) {
	// 	size_t idx = order[oi];
	// 	int x = pend[idx];
	// 	size_t p = lowerBoundDeq(mainc, x);
	// 	mainc.insert(mainc.begin() + (std::deque<int>::difference_type)p, x);
	// }

	return mainc;
}

void PmergeMe::run(int ac, char** av)
{
	parseArgs(ac, av);

	printSequence("Before: ", _deq);

	double t1 = nowMicros();
	std::deque<MultiLevelPairs> sortedD = fordJohnsonDeque(_deq);
	double t2 = nowMicros();

	printSequence("After:  ", sortedD);

	std::cout << "Time to process a range of " << _deq.size()
	          << " elements with std::deque  : " << (t1 - t2) << " us" << std::endl;
}
