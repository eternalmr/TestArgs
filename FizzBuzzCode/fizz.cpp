#include "fizz.h"

bool is_related_to(int n, int i)
{
	return i % n == 0;
}

std::string GameNumber(int i)
{
	if (is_related_to(3, i) && is_related_to(5, i)) return "fizzbuzz";
	if (is_related_to(5, i)) return "buzz";
	if (is_related_to(3, i)) return "fizz";
	return std::to_string(i);
}