/*
 * main.cpp
 *
 *  Created on: 05/08/2015
 *      Author: pperezm
 */
#include <iostream>
#include <cstring>
#include "unit.h"
#include "list.h"

class ListTest : public UnitTest {
public:
	void runTest() {
		list<int> b1, b2;
		UnitTest::total_test = 11;
		
		b1.push_back(2); b1.push_back(3); b1.push_back(4);
		b2.push_back(2); b2.push_back(3); b2.push_back(4);
		
		/* TEST 1 */
		b1.set(0, 1);
		ASSERT_TRUE(!strcmp("[1, 3, 4]", b1.to_string().c_str()));
		std::cout << " PASSED.\nTest 2";
		
		/* TEST 2 */
		b1.set(1, 2);
		ASSERT_TRUE(!strcmp("[1, 2, 4]", b1.to_string().c_str()));
		std::cout << " PASSED.\nTest 3";
		
		/* TEST 3 */
		try {
			b1.set(-1, 10);
			FAIL("IndexOutOfBounds not thrown");
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("IndexOutOfBounds", e.what()));
			std::cout << " PASSED.\nTest 4";
		}
		
		/* TEST 4 */
		try {
			b1.set(3, 10);
			FAIL("IndexOutOfBounds not thrown");
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("IndexOutOfBounds", e.what()));
			std::cout << " PASSED.\nTest 5";
		}
		
		/* TEST 5 */
		b1.push_front(1);
		b1.push_back(1);
		b1.push_back(5);
		b1.push_back(1);
		ASSERT_TRUE(0 == b1.index_of(1));
		std::cout << " PASSED.\nTest 6";
		
		/* TEST 6 */
		ASSERT_TRUE(6 == b1.last_index(1));
		std::cout << " PASSED.\nTest 7";
		
		/* TEST 7 */
		ASSERT_TRUE(1 == b1.remove(4));
		ASSERT_TRUE(6 == b1.length());
		ASSERT_TRUE(!strcmp("[1, 1, 2, 4, 5, 1]", b1.to_string().c_str()));
		std::cout << " PASSED.\nTest 8";
		
		/* TEST 8 */
		ASSERT_TRUE(true == b1.remove_first_ocurrence(1));
		ASSERT_TRUE(5 == b1.length());
		ASSERT_TRUE(!strcmp("[1, 2, 4, 5, 1]", b1.to_string().c_str()));
		std::cout << " PASSED.\nTest 9";
		
		/* TEST 9 */
		ASSERT_TRUE(false == b1.remove_first_ocurrence(100));
		std::cout << " PASSED.\nTest 10";
		
		/* TEST 10 */
		ASSERT_TRUE(true == b1.remove_last_ocurrence(1));
		ASSERT_TRUE(4 == b1.length());
		ASSERT_TRUE(!strcmp("[1, 2, 4, 5]", b1.to_string().c_str()));
		std::cout << " PASSED.\nTest 11";
		
		/* TEST 11 */
		ASSERT_TRUE(false == b1.remove_last_ocurrence(100));
		std::cout << " PASSED.";
	}
};

int main(int argc, char* argv[]) {
	ListTest test;

	test.runTest();
	std::cout << "SUCESS!\n";
	return 0;
}


