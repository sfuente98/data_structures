/*
 * main.cpp
 *
 *  Created on: 29/10/2015
 *      Author: pperezm
 */

#include <iostream>
#include <cstring>
#include "../includes/unit.h"
#include "evaltree.h"

using namespace std;

class EvalTreeTest : public UnitTest {
public:
	void runTest() {
		UnitTest::total_test = 17;

		/* TEST 1 */
		cout << "Test 1";
		try {
			eval_tree a("1 2 + 11 3 *");
			FAIL("IllegalAction not thrown");
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("IllegalAction", e.what()));
			std::cout << " PASSED.\nTest 2";
		}

		eval_tree a("10 3 * 2 2 * - 1 +");
		eval_tree b;
		/* TEST 2 */
		ASSERT_TRUE(!strcmp("1 + 2 * 2 - 3 * 10 ", a.inorder().c_str()));
		std::cout << " PASSED.\nTest 3";

		/* TEST 3 */
		ASSERT_TRUE(!strcmp("+ 1 - * 2 2 * 3 10 ", a.preorder().c_str()));
		std::cout << " PASSED.\nTest 4";

		/* TEST 4 */
		ASSERT_TRUE(!strcmp("1 2 2 * 3 10 * - + ", a.postorder().c_str()));
		std::cout << " PASSED.\nTest 5";

		/* TEST 5 */
		ASSERT_TRUE(!strcmp("+ 1 - * * 2 2 3 10 ", a.breadth_order().c_str()));
		std::cout << " PASSED.\nTest 6";

		/* TEST 6 */
		ASSERT_TRUE(b.empty() == true);
		std::cout << " PASSED.\nTest 7";

		/* TEST 7 */
		ASSERT_TRUE(a.empty() == false);
		std::cout << " PASSED.\nTest 8";

		/* TEST 8 */
		ASSERT_TRUE(b.depth() == 0);
		std::cout << " PASSED.\nTest 9";

		/* TEST 9 */
		ASSERT_TRUE(a.depth() == 4);
		std::cout << " PASSED.\nTest 10";
		
		/* TEST 10 */
		ASSERT_TRUE(b.leaves() == 0);
		std::cout << " PASSED.\nTest 11";

		/* TEST 11 */
		ASSERT_TRUE(a.leaves() == 5);
		std::cout << " PASSED.\nTest 12";

		/* TEST 12 */
		try {
			b.min_value();
			FAIL("IllegalAction not thrown");
		} catch (std::exception &e) {
			ASSERT_TRUE(!strcmp("IllegalAction", e.what()));
			std::cout << " PASSED.\nTest 13";
		}

		/* TEST 13 */
		ASSERT_TRUE(a.min_value() == 1);
		std::cout << " PASSED.\nTest 14";

		/* TEST 14 */
		tree_value val;
		val.number = 1;
		ASSERT_TRUE(a.find(NUMBER, val) == true);
		std::cout << " PASSED.\nTest 15";
		
		/* TEST 15 */
		val.number = 9;
		ASSERT_TRUE(a.find(NUMBER, val) == false);
		std::cout << " PASSED.\nTest 16";

		/* TEST 16 */
		ASSERT_TRUE(a.eval() == -25);
		std::cout << " PASSED.\n";
	}
};

int main(int argc, char* argv[]) {
	EvalTreeTest test;

	test.runTest();
	std::cout << "SUCESS!\n";
	return 0;
}


