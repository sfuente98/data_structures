/**
    File: main.cpp
    Purpose: This file defines a series of tests for the rational class

    @author Pedro Perez
    @version 2.0 13/01/2019
*/
#include <iostream>
#include <cstring>
#include "../includes/unit.h"
#include "rational.h"

class rationalTest : public UnitTest {
public:
	void runTest() {
		rational r;
		UnitTest::total_test = 29;

		/* TEST 1 */
		std::cout << "Test 1...";
		ASSERT_TRUE(!strcmp("0/1", rational().to_string().c_str()));
		std::cout << " PASSED\n Test 2...";

		/* TEST 2 */
		std::cout << "mi resultado" << rational(10).to_string().c_str() << "\n";
		ASSERT_TRUE(!strcmp("10/1", rational(10).to_string().c_str()));
		std::cout << " PASSED\n Test 3...";

		/* TEST 3 */

		std::cout << "mi resultado" << rational(2,4).to_string().c_str() << "\n";
		ASSERT_TRUE(!strcmp("1/2", rational(2,4).to_string().c_str()));
		std::cout << " PASSED\n Test 4...";

		/* TEST 4 */
		ASSERT_TRUE(!strcmp("3/11", rational(3,11).to_string().c_str()));
		std::cout << " PASSED\n Test 5...";

		/* TEST 5 */
		ASSERT_TRUE(!strcmp("1/512", rational(4,2048).to_string().c_str()));
		std::cout << " PASSED\n Test 6...";

		/* TEST 6 */
		ASSERT_TRUE(!strcmp("-1/2", rational(1,-2).to_string().c_str()));
		std::cout << " PASSED\n Test 7...";

		/* TEST 7 */
		ASSERT_TRUE(!strcmp("-1/2", rational(-1,2).to_string().c_str()));
		std::cout << " PASSED\n Test 8...";

		/* TEST 8 */
		ASSERT_TRUE(!strcmp("1/2", rational(-1,-2).to_string().c_str()));
		std::cout << " PASSED\n Test 9...";

		/* TEST 9 */
		try {
			rational(1,0);
			FAIL("RangeError not thrown");
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("RangeError", e.what()));
			std::cout << " PASSED\n Test 10...";
		}

		/* TEST 10 */
		r = rational(1, 3);
		ASSERT_TRUE(!strcmp("1/3", r.to_string().c_str()));
		std::cout << " PASSED\n Test 11...";

		/* TEST 11 */
		r += rational(2, 3);
		ASSERT_TRUE(!strcmp("1/1", r.to_string().c_str()));
		std::cout << " PASSED\n Test 12...";

		/* TEST 12 */
		r = rational(2, 3);
		r += rational(5, 8);
		ASSERT_TRUE(!strcmp("31/24", r.to_string().c_str()));
		std::cout << " PASSED\n Test 13...";

		/* TEST 13 */
		ASSERT_TRUE(0.5 == ((double) rational(1,2)));
		std::cout << " PASSED\n Test 14...";

		/* TEST 14 */
		ASSERT_TRUE(0.625 == ((double) rational(5,8)));
		std::cout << " PASSED\n Test 15...";

		/* TEST 15 */
		ASSERT_TRUE(0 == ((double) rational()));
		std::cout << " PASSED\n Test 16...";

		/* TEST 16 */
		r = rational(1,3) + rational(2,3);
		ASSERT_TRUE(!strcmp("1/1", r.to_string().c_str()));
		std::cout << " PASSED\n Test 17...";

		/* TEST 17 */
		r = rational(2,3) + rational(5,8);
		ASSERT_TRUE(!strcmp("31/24", r.to_string().c_str()));
		std::cout << " PASSED\n Test 18...";

		/* TEST 18 */
		r = -rational(1,3);
		ASSERT_TRUE(!strcmp("-1/3", r.to_string().c_str()));
		std::cout << " PASSED\n Test 19...";

		/* TEST 19 */
		r = -rational(-1,3);
		ASSERT_TRUE(!strcmp("1/3", r.to_string().c_str()));
		std::cout << " PASSED\n Test 20...";

		/* TEST 20 */
		r = -rational(-1,-3);
		ASSERT_TRUE(!strcmp("-1/3", r.to_string().c_str()));
		std::cout << " PASSED\n Test 21...";

		/* TEST 21 */
		r = rational(1, 3) - rational(2, 3);
		ASSERT_TRUE(!strcmp("-1/3", r.to_string().c_str()));
		std::cout << " PASSED\n Test 22...";

		/* TEST 22 */
		r = rational(2, 3) - rational(1, 3);
		ASSERT_TRUE(!strcmp("1/3", r.to_string().c_str()));
		std::cout << " PASSED\n Test 23...";

		/* TEST 23 */
		r = rational(5, 8) - rational(2, 3);
		ASSERT_TRUE(!strcmp("-1/24", r.to_string().c_str()));
		std::cout << " PASSED\n Test 24...";

		/* TEST 24 */
		r = rational(2, 3) - rational(5, 8);
		ASSERT_TRUE(!strcmp("1/24", r.to_string().c_str()));
		std::cout << " PASSED\n Test 25...";

		/* TEST 25 */
		ASSERT_TRUE(rational(1, 512) == rational(4, 2048));
		std::cout << " PASSED\n Test 26...";

		/* TEST 26 */
		ASSERT_FALSE(rational(2, 3) == rational(5, 8));
		std::cout << " PASSED\n Test 27...";

		/* TEST 27 */
		ASSERT_TRUE(rational(5, 8) < rational(2, 3));
		std::cout << " PASSED\n Test 28...";

		/* TEST 28 */
		ASSERT_FALSE(rational(2, 3) < rational(5, 8));
		std::cout << " PASSED\n Test 29...";

		/* TEST 29 */
		ASSERT_FALSE(rational(2, 3) < rational(2, 3));
		std::cout << " PASSED\n";
	}
};

int main(int argc, char* argv[]) {
	rationalTest test;

	test.runTest();
	std::cout << "SUCCESS!\n";
	return 0;
}
