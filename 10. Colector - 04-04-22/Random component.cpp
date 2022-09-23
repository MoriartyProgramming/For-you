#include <iostream>
#include <random>

int randomize(int barier)
{
	std::random_device rd;
	std::mt19937 mersenne(rd());

	return mersenne() % barier + 2;
}