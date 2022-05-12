#pragma once
#include"../Model/Interval.h"
//#include"../Model/Interval.h"
#define DOCTEST_CONFIG_IMPLEMENT
#include"../doctest.h"

TEST_CASE("OPERATOR==") {
	Interval a({ 2022, 5, 1 }, 5);
	Interval b({ 2022, 5, 3 }, 1);
	CHECK_EQ(a == b, true);
}

TEST_CASE("OPERATOR==") {
	Interval a({ 2022, 5, 1 }, 5);
	Interval b({ 2022, 5, 8 }, 1);
	CHECK_EQ(a == b, false);
}

TEST_CASE("OPERATOR==") {
	Interval b({ 2022, 5, 1 }, 5);
	Interval a({ 2022, 5, 3 }, 1);
	CHECK_EQ(a == b, true);
}

TEST_CASE("OPERATOR==") {
	Interval b({ 2022, 5, 1 }, 5);
	Interval a({ 2022, 5, 8 }, 1);
	CHECK_EQ(a == b, false);
}

TEST_CASE("OPERATOR==") {
	Interval a({ 2022, 5, 1 }, 1);
	Interval b({ 2022, 5, 12 }, 1);
	CHECK_EQ(a == b, false);
}