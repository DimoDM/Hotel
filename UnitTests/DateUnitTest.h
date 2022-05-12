#pragma once
#include"../Model/Date.h"
#define DOCTEST_CONFIG_IMPLEMENT
#include"../doctest.h"

TEST_CASE("OPERATOR<") {
	Date a({ 2022, 5, 1 });
	Date b({ 2022, 5, 3 });
	CHECK_EQ(a < b, true);
}

TEST_CASE("OPERATOR<") {
	Date a({ 2022, 5, 1 });
	Date b({ 2022, 5, 3 });
	CHECK_EQ(b < a, false);
}

TEST_CASE("OPERATOR<") {
	Date a({ 2022, 5, 1 });
	Date b({ 2022, 5, 1 });
	CHECK_EQ(b < a, false);
}

TEST_CASE("OPERATOR==") {
	Date a( 2022, 5, 1 );
	Date b( 2022, 5, 1 );
	CHECK_EQ(b == a, true);
}

TEST_CASE("OPERATOR==") {
	Date a( 2022, 5, 1 );
	Date b( 2022, 5, 2 );
	CHECK_EQ(b == a, false);
}

TEST_CASE("OPERATOR+=") {
	Date a(2022, 5, 1 );
	a += 5;
	Date b( 2022, 5, 6 );
	CHECK_EQ(b, a);
}

TEST_CASE("OPERATOR+=") {
	Date a(2022, 1, 1 );
	a += 64;
	Date b( 2022, 3, 6 );
	CHECK_EQ(b == a, true);
}

TEST_CASE("OPERATOR+=") {
	Date a(2021, 12, 1);
	a += 95;
	Date b(2022, 3, 6);
	CHECK_EQ(b == a, true);
}