/*
 * main.cpp
 *
 *  Created on: 05/08/2015
 *      Author: pperezm
 */
#include <iostream>
#include <cstring>
#include "../includes/unit.h"
#include "list.h"

class ListTest : public UnitTest {
public:
	void runTest() {
		list<int> b1;
		UnitTest::total_test = 33;

		/* TEST 1 */
		std::cout << "Test 1";
		ASSERT_TRUE(0 == b1.length());
		std::cout << " PASSED.\nTest 2";

		/* TEST 2 */
		ASSERT_TRUE(!strcmp("[]", b1.to_string().c_str()));
		std::cout << " PASSED.\nTest 3";

		/* TEST 3 */
		b1.push_front(2);
		ASSERT_TRUE(1 == b1.length());
		ASSERT_TRUE(!strcmp("[2]", b1.to_string().c_str()));
		std::cout << " PASSED.\nTest 4";

		/* TEST 4 */
		b1.push_front(1);
		ASSERT_TRUE(2 == b1.length());
		ASSERT_TRUE(!strcmp("[1, 2]", b1.to_string().c_str()));
		std::cout << " PASSED.\nTest 5";

		/* TEST 5 */
		b1.push_back(3);
		ASSERT_TRUE(3 == b1.length());
		ASSERT_TRUE(!strcmp("[1, 2, 3]", b1.to_string().c_str()));
		std::cout << " PASSED.\nTest 6";

		/* TEST 6 */
		b1.push_back(4);
		ASSERT_TRUE(4 == b1.length());
		ASSERT_TRUE(!strcmp("[1, 2, 3, 4]", b1.to_string().c_str()));
		std::cout << " PASSED.\nTest 7";

		/* TEST 7 */
		list<int> b2(b1);
		ASSERT_TRUE(4 == b2.length());
		ASSERT_TRUE(!strcmp("[1, 2, 3, 4]", b2.to_string().c_str()));
		std::cout << " PASSED.\nTest 8";

		/* TEST 8 */
		b2.clear();
		ASSERT_TRUE(0 == b2.length());
		ASSERT_TRUE(true == b2.empty());
		ASSERT_TRUE(!strcmp("[]", b2.to_string().c_str()));
		std::cout << " PASSED.\nTest 9";

		/* TEST 9 */
		ASSERT_TRUE(1 == b1.front());
		std::cout << " PASSED.\nTest 10";

		/* TEST 10 */
		try {
			b2.front();
			FAIL("NoSuchElement not thrown");
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("NoSuchElement", e.what()));
			std::cout << " PASSED.\nTest 11";
		}

		/* TEST 11 */
		ASSERT_TRUE(1 == b1.pop_front());
		ASSERT_TRUE(3 == b1.length());
		ASSERT_TRUE(!strcmp("[2, 3, 4]", b1.to_string().c_str()));
		std::cout << " PASSED.\nTest 12";

		/* TEST 12 */
		try {
			b2.pop_front();
			FAIL("NoSuchElement not thrown");
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("NoSuchElement", e.what()));
			std::cout << " PASSED.\nTest 13";
		}
		
		/* TEST 11 */
		ASSERT_TRUE(4 == b1.pop_back());
		ASSERT_TRUE(2 == b1.length());
		ASSERT_TRUE(!strcmp("[2, 3]", b1.to_string().c_str()));
		std::cout << " PASSED.\nTest 14";

		/* TEST 12 */
		try {
			b2.pop_back();
			FAIL("NoSuchElement not thrown");
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("NoSuchElement", e.what()));
			std::cout << " PASSED.\nTest 14";
		}

		b1.push_back(4);
		/* TEST 13 */
		ASSERT_TRUE(2 == b1.get(0));
		std::cout << " PASSED.\nTest 15";

		/* TEST 14 */
		ASSERT_TRUE(3 == b1.get(1));
		std::cout << " PASSED.\nTest 16";

		/* TEST 15 */
		ASSERT_TRUE(4 == b1.get(2));
		std::cout << " PASSED.\nTest 17";

		/* TEST 16 */
		try {
			b1.get(-1);
			FAIL("IndexOutOfBounds not thrown");
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("IndexOutOfBounds", e.what()));
			std::cout << " PASSED.\nTest 18";
		}

		/* TEST 17 */
		try {
			b1.get(3);
			FAIL("IndexOutOfBounds not thrown");
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("IndexOutOfBounds", e.what()));
			std::cout << " PASSED.\nTest 19";
		}

		/* TEST 18 */
		ASSERT_TRUE(true == b1.contains(3));
		std::cout << " PASSED.\nTest 20";

		/* TEST 19 */
		ASSERT_TRUE(false == b1.contains(10));
		std::cout << " PASSED.\nTest 21";

		/* TEST 20 */
		ASSERT_TRUE(false == b1.empty());
		std::cout << " PASSED.\nTest 22";

		/* TEST 21 */
		ASSERT_TRUE(true == b2.empty());
		std::cout << " PASSED.\nTest 23";

		/* TEST 22 */
		b2 = b1;
		ASSERT_TRUE(3 == b2.length());
		ASSERT_TRUE(!strcmp("[2, 3, 4]", b2.to_string().c_str()));
		std::cout << " PASSED.\n";		
	}
};

int main(int argc, char* argv[]) {
	ListTest test;

	test.runTest();
	std::cout << "SUCESS!\n";
	return 0;
}


