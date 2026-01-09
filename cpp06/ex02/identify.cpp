
#include "identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>   // rand
#include <iostream>
#include <exception> // bad_cast

Base* generate(void)
{
	int r = std::rand() % 3;

	if (r == 0) return new A();
	if (r == 1) return new B();
	return new C();
}

void identify(Base* p)
{
	if (!p) {
		std::cout << "Unknown\n";
		return;
	}

	if (dynamic_cast<A*>(p)) {
		std::cout << "A\n";
		return;
	}
	if (dynamic_cast<B*>(p)) {
		std::cout << "B\n";
		return;
	}
	if (dynamic_cast<C*>(p)) {
		std::cout << "C\n";
		return;
	}
	std::cout << "Unknown\n";
}

void identify(Base& p)
{
	// No pointers allowed inside this function.
	// For references, dynamic_cast throws std::bad_cast on failure.
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
		return;
	} catch (std::exception const &) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
		return;
	} catch (std::exception const &) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
		return;
	} catch (std::exception const &) {}

	std::cout << "Unknown\n";
}