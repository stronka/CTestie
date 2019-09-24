#include "ctestie.h"

#include "simple_operations.c"

TEST test_Add_ChangeArgumentOrder_ResultIsTheSame(){
	ASSERT(add(2, 1) == add(1, 2), "Fail. Argument order should not matter.");
};

TEST test_Add_AddOneAndZero_ReturnsOne(){
	double actual = add(1, 0);
	double expected = 1;

	ASSERT(actual == expected, "Fail. Zero should be a neutral element of addition.");
};

TEST test_Add_AddZeroAndTwo_ReturnsTwo(){
	double actual = add(0, 2);
	double expected = 2;

	ASSERT(actual == expected, "Fail. Zero should be a neutral element of addition.");
};

TEST test_Add_AddOneAndTwo_ReturnsThree(){
	double actual = add(1, 2);
	double expected = 3;

	ASSERT(actual == expected, "Fail. Got %.2f but expected %.2f", actual, expected);
};

RUN(
	test_Add_ChangeArgumentOrder_ResultIsTheSame,
	test_Add_AddOneAndZero_ReturnsOne,
	test_Add_AddZeroAndTwo_ReturnsTwo,
	test_Add_AddOneAndTwo_ReturnsThree
);

