#include "pch.h"
#include "fizz.h"
//
//bool is_related_to(int n, int i)
//{
//	return i % n == 0;
//}
//
//std::string GameNumber(int i)
//{
//	if (is_related_to(3, i) && is_related_to(5, i)) return "fizzbuzz";
//	if (is_related_to(5, i)) return "buzz";
//	if (is_related_to(3,i)) return "fizz";
//	return std::to_string(i);
//}

TEST(should_show_fizzbuzz_if_is_divisible_by_3_and_5, test4)
{
	EXPECT_EQ(GameNumber(15), "fizzbuzz");
	EXPECT_EQ(GameNumber(30), "fizzbuzz");
}

TEST(should_show_raw_number_if_is_normal_numbers, test1)
{
	EXPECT_EQ(GameNumber(1), "1");
}

TEST(should_show_fizz_if_is_divisible_by_3, test2)
{
	EXPECT_EQ(GameNumber(3), "fizz");
}

TEST(should_show_buzz_if_is_divisible_5, test3)
{
	EXPECT_EQ(GameNumber(5), "buzz");
}