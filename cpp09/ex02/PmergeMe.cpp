/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capapes <capapes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:33:38 by capapes           #+#    #+#             */
/*   Updated: 2026/01/13 20:09:29 by capapes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <cctype>
#include <sys/time.h>
#include <cmath>

// ------------------------------------------------------------------------------------- OCF Start
PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& o) : _deq(o._deq) {}
PmergeMe& PmergeMe::operator=(const PmergeMe& o) {
	if (this != &o) { _deq = o._deq; }
	return *this;
}
PmergeMe::~PmergeMe() {}

// ------------------------------------------------------------------------------------- OCF End
// ------------------------------------------------------------------------------------- Printers start
void printSequence(const std::string& label, const std::deque< MultiLevelPairsDq>& d) {
	std::cout << label;
	const size_t limit = 20;
	for (size_t i = 0; i < d.size() && i < limit; ++i)
			std::cout <<  d[i].lead << " ";
	if (d.size() > limit) std::cout << " [...]";
	std::cout << "\n" << std::endl;
}

void printSequenceV(const std::string& label, const std::vector< MultiLevelPairsVc>& d) {
	std::cout << label;
	const size_t limit = 20;
	for (size_t i = 0; i < d.size() && i < limit; ++i)
			std::cout <<  d[i].lead << " ";
	if (d.size() > limit) std::cout << " [...]";
	std::cout << "\n" << std::endl;
}

#define GRAY "\033[90m"
#define BOLD  "\033[1m"
#define RESET "\033[0m"

void printNodeBracket(const MultiLevelPairsDq& node, bool isLead, int level)
{
	if (node.levels.empty()) 
	{ 
		isLead 
			? std::cout << RESET << BOLD << node.lead << RESET << GRAY
			: std::cout << node.lead ;
		if (level == 0)
			std::cout << " ";
		return; 
	}
	
	level == 0 
		? std::cout << RESET << BOLD << " [" << RESET << GRAY
		: std::cout << "["; 
	
	if (!node.levels.empty()) 
	{ 
		printNodeBracket(node.levels[0], isLead && false, level + 1);
		if (node.levels[0].levels.empty() && node.levels.size() > 1) std::cout << "|" ;
		if (node.levels.size() > 1)
			printNodeBracket(node.levels[1], isLead && true, level + 1);
	}
	level == 0 
		? std::cout << RESET << BOLD << "] " 
		: std::cout << "]"; 
}


void printNodes(const std::deque<MultiLevelPairsDq> nodes, std::string title)
{
	std::cout << title << " \t";
	for (size_t i = 0; i < nodes.size(); i++)
		printNodeBracket(nodes[i], true, 0);
	std::cout << std::endl;
}

void printStatus(const std::deque<MultiLevelPairsDq> nodes, const MultiLevelPairsDq stray, std::string title)
{
	std::cout << "L"<< nodes[0].level << "\t";
	printNodes(nodes, title);
	std::cout << std::endl;

	if (stray.levels.empty())
		return;
	std::cout << RESET << GRAY << "\tstray  \t\t";
	printNodeBracket(stray, false, 0);
	std::cout << "\n" << std::endl;
}

void upperBoundDebug(const std::deque<MultiLevelPairsDq>& main, int x, int y)
{
	std::cout << "\n\tLEVEL DEBUG START POINT:" << main[y].lead;
	std::cout << "\n\tCOMPARISION DEBUG:" << x << "\n" << std::endl;
	std::cout << "\n\tNOW START FROM:" << y << std::endl;
	std::cout << "\t";
	printNodes(main, "TO COMPARE:");
	std::cout << "\n";
}

void printInsertionOrder(std::vector<size_t> order)
{
	std::cout << "\n\tINSERTION ORDER:";
	for (size_t i = 0; i < order.size(); i++)
	std::cout << order[i] << " ";
	std::cout << "\n";
	std::cout << std::endl;
}
// -------------------------------------------------------------------------------------  Printers End
// ------------------------------------------------------------------------------------- Helpers start
double PmergeMe::nowMicros() {
	timeval tv;
	gettimeofday(&tv, 0);
	return (double)tv.tv_sec * 1000000.0 + (double)tv.tv_usec;
}

int maxComparations(int n)
{
    int sum = 0;
    for (int k = 1; k <= n; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
    return sum;
}

void comparisionCount(int mode)
{
	static int i = 0;
	if (mode == 0)
		i++;
	if (mode == 1)
		std::cout << "COMPARED\t" << i << std::endl;
}

std::deque<MultiLevelPairsDq> flatten(const std::deque<MultiLevelPairsDq>& nodes)
{
    std::deque<MultiLevelPairsDq> out;
    if (nodes.empty())
        return out;

    for (size_t i = 0; i < nodes.size(); ++i)
    {
        const MultiLevelPairsDq& n = nodes[i];
        out.insert(out.end(), n.levels.begin(), n.levels.end());
    }

    return out;
}


std::vector<MultiLevelPairsVc> flattenV(const std::vector<MultiLevelPairsVc>& nodes)
{
    std::vector<MultiLevelPairsVc> out;
    if (nodes.empty())
        return out;

   for (size_t i = 0; i < nodes.size(); ++i)
    {
        const MultiLevelPairsVc& n = nodes[i];
        out.insert(out.end(), n.levels.begin(), n.levels.end());
    }

    return out;
}


// ------------------------------------------------------------------------------------- Helpers End
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
	_vec.clear();

	for (int i = 1; i < ac; ++i) {
		std::string tok(av[i]);
		if (!isPositiveIntToken(tok))
			throw std::runtime_error("Error 1");
		long x = toLong(tok);
		if (x < 0 || x > 2147483647L)
			throw std::runtime_error("Error 2");
		
		MultiLevelPairsDq nextD;
		nextD.lead = x;
		nextD.level = 0;
		_deq.push_back(nextD);

		MultiLevelPairsVc nextV;
		nextV.lead = x;
		nextV.level = 0;
		_vec.push_back(nextV);
	}
	if (_deq.empty())
		throw std::runtime_error("Error 3");
}

// ------------------------------------------------------------------------------------- Prase Args ends
// ------------------------------------------------------------------------------------- Sort alg helpers start

static size_t jacob(size_t n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	size_t a = 0, b = 1;
	for (size_t i = 2; i <= n; ++i) {
		size_t c = b + 2 * a;
		a = b;
		b = c;
	}
	return b;
}



static std::vector<size_t> jacobOrder(size_t nodesQty)
{
	std::vector<size_t> order;
	if (nodesQty <= 1) return order;

	size_t prevJacobNumber = 0;
	size_t bk = 2;

	while (true) {
		size_t jacobNumber = jacob(bk);
		if (jacobNumber >= nodesQty) break;
		for (size_t i = jacobNumber; i > prevJacobNumber; --i)
			order.push_back(i);
		prevJacobNumber = jacobNumber;
		++bk;
	}
	for (size_t i = nodesQty - 1; i > prevJacobNumber; --i)
		order.push_back(i);

	// printInsetionOrder(order);
	return order;
}

static size_t upperBoundLead(const std::deque<MultiLevelPairsDq>& main, int x, int y)
{

	// upperBoundDebug(main, x, y);

	size_t pos = 0, range = y - 1;
	while (pos < range) {
		size_t mid = pos + (range - pos) / 2;
		// ------------------------------------------------------------------------------- COMPARISION++
		comparisionCount(0);
		// ---------------------------------------------------------------------------------
		if (main[mid].lead < x)
			pos = mid + 1;
		else range = mid;
	}
	return pos;
}

static size_t upperBoundLead(const std::vector<MultiLevelPairsVc>& main, int x, int y)
{
	size_t pos = 0, range = y - 1;
	while (pos < range) {
		size_t mid = pos + (range - pos) / 2;
		if (main[mid].lead < x)
			pos = mid + 1;
		else range = mid;
	}
	return pos;
}

// ------------------------------------------------------------------------------------- Sort alg helpers end
void makePairsOnce(const std::deque<MultiLevelPairsDq>& input,
                   std::deque<MultiLevelPairsDq>& pairs,
                   MultiLevelPairsDq& stray)
{
    pairs.clear();

    for (size_t i = 0; i + 1 < input.size(); i += 2)
    {
        const MultiLevelPairsDq& a = input[i];
		const MultiLevelPairsDq& b = input[i + 1];
		MultiLevelPairsDq next;
		// ------------------------------------------------------------------------------- COMPARISION++
		comparisionCount(0);
		const bool aGreater = (a.lead > b.lead);
		// ---------------------------------------------------------------------------------
		next.levels.push_back(aGreater ? b : a);
		next.levels.push_back(aGreater ? a : b);
		next.lead = next.levels.back().lead;
		next.level = a.level + 1;

		pairs.push_back(next);
    }

    if (input.size() % 2 == 1)
		stray.levels.push_front(input.back());
	// comparisionCount(1);
}

static void insertPending(std::deque<MultiLevelPairsDq>& main,
                          const std::deque<MultiLevelPairsDq>& pending)
{
	if (pending.empty())
		return;
	std::vector<size_t> order = jacobOrder(pending.size() + 1);
	
	main.push_front(pending[0]);
	for (size_t oi = 1 ; oi < order.size(); oi++)
	{
		size_t idx = order[oi] - 1;
		size_t pos = upperBoundLead(main, pending[idx].lead, order[oi] + oi);
		
		main.insert(main.begin() + (std::deque<MultiLevelPairsDq>::difference_type)pos,
		            pending[idx]);
	}
}



std::deque< MultiLevelPairsDq> PmergeMe::fordJohnsonDeque(std::deque<MultiLevelPairsDq> nodes)
{
	std::deque<MultiLevelPairsDq> paired;
	MultiLevelPairsDq stray;

	if (nodes.size() <= 1) return nodes;
	
    while (nodes.size() > 1)
    {
        makePairsOnce(nodes, paired, stray);
		nodes.swap(paired);
		// printStatus(nodes, stray, "PHASE 1");
    }

	while (true)
	{
		while (!stray.levels.empty() && stray.levels[0].level == nodes[0].level)
		{
			nodes.push_back(stray.levels.front());
			stray.levels.pop_front();
		}

		std::deque<MultiLevelPairsDq> maindq;
		std::deque<MultiLevelPairsDq> penddq;

		for (size_t i = 0; i + 1 < nodes.size(); i +=2)
		{
			penddq.push_back(nodes[i]);
			maindq.push_back(nodes[i + 1]);
		}
		if (nodes.size() % 2)
			penddq.push_back(nodes.back());
		// printNodes(maindq, "\tMAIN\t");
		// printNodes(penddq, "\tPEND\t");

		insertPending(maindq, penddq);
		// printNodes(maindq, "\tINSERT\t");

		if (nodes[0].levels.empty())
		{
			nodes = maindq;
			break;
		}
		nodes = flatten(maindq);
		// comparisionCount(1);
	}
    return nodes;
}

// ------------------------------------------------------------------------------------- VECTO ALG
void makePairsOnceVc(const std::vector<MultiLevelPairsVc>& input,
                   std::vector<MultiLevelPairsVc>& pairs,
                   MultiLevelPairsVc& stray)
{
    pairs.clear();

    for (size_t i = 0; i + 1 < input.size(); i += 2)
    {
        const MultiLevelPairsVc& a = input[i];
		const MultiLevelPairsVc& b = input[i + 1];
		MultiLevelPairsVc next;
		const bool aGreater = (a.lead > b.lead);
		next.levels.push_back(aGreater ? b : a);
		next.levels.push_back(aGreater ? a : b);
		next.lead = next.levels.back().lead;
		next.level = a.level + 1;

		pairs.push_back(next);
    }

    if (input.size() % 2 == 1)
		stray.levels.insert(stray.levels.begin(), input.back());
	// comparisionCount(1);
}

static void insertPending(std::vector<MultiLevelPairsVc>& main,
                          const std::vector<MultiLevelPairsVc>& pending)
{
	if (pending.empty())
		return;
	std::vector<size_t> order = jacobOrder(pending.size() + 1);
	
	main.insert(main.begin(), pending[0]);
	for (size_t oi = 1 ; oi < order.size(); oi++)
	{
		size_t idx = order[oi] - 1;
		size_t pos = upperBoundLead(main, pending[idx].lead, order[oi] + oi);
		
		main.insert(main.begin() + (std::deque<MultiLevelPairsVc>::difference_type)pos,
		            pending[idx]);
	}
}

std::vector< MultiLevelPairsVc> PmergeMe::fordJohnsonVector(std::vector<MultiLevelPairsVc> nodes)
{
	std::vector<MultiLevelPairsVc> paired;
	MultiLevelPairsVc stray;

	if (nodes.size() <= 1) return nodes;
	
    while (nodes.size() > 1)
    {
        makePairsOnceVc(nodes, paired, stray);
		nodes.swap(paired);
    }

	while (true)
	{
		while (!stray.levels.empty() && stray.levels[0].level == nodes[0].level)
		{
			nodes.push_back(stray.levels.front());
			stray.levels.erase(stray.levels.begin());
		}

		std::vector<MultiLevelPairsVc> maindq;
		std::vector<MultiLevelPairsVc> penddq;

		for (size_t i = 0; i + 1 < nodes.size(); i +=2)
		{
			penddq.push_back(nodes[i]);
			maindq.push_back(nodes[i + 1]);
		}
		if (nodes.size() % 2)
			penddq.push_back(nodes.back());

		insertPending(maindq, penddq);

		if (nodes[0].levels.empty())
		{
			nodes = maindq;
			break;
		}
		nodes = flattenV(maindq);
	}
    return nodes;
}

void PmergeMe::run(int ac, char** av)
{
	parseArgs(ac, av);
	// comparisionCount(1);

	// DEQUE
	printSequence("Before dq: ", _deq);
	std::deque<MultiLevelPairsDq> sortedD = fordJohnsonDeque(_deq);
	printSequence("After dq:  ", sortedD);

	// VECTOR
	printSequenceV("Before vc: ", _vec);
	std::vector<MultiLevelPairsVc> sortedV = fordJohnsonVector(_vec);
	printSequenceV("After vc:  ", sortedV);

	// std::cout << "B QTY\t" << _deq.size() << std::endl;
	// std::cout << "E QTY\t" << sortedD.size() << std::endl;
	// comparisionCount(1);
	// std::cout << "EXPECTED\t" << maxComparations(ac-1);
}

