#include "ctestie.h"

#include "simple_operations.c"

TEST test_Add_AddOneAndZero_ReturnsOne(){
	double actual = add(1, 0);
	double expected = 1;

	ASSERT(actual == expected, "Fail.");
};

TEST test_Add_AddZeroAndTwo_ReturnsTwo(){
	double actual = add(0, 2);
	double expected = 2;

	ASSERT(actual == expected, "Fail.");
};

TEST test_Add_AddOneAndTwo_ReturnsThree(){
	double actual = add(1, 2);
	double expected = 3;

	ASSERT(actual == expected, "Fail.");
};

RUN(
	test_Add_AddOneAndZero_ReturnsOne,
	test_Add_AddZeroAndTwo_ReturnsTwo,
	test_Add_AddOneAndTwo_ReturnsThree
);

