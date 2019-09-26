CTestie
===========
Minimal unit test framework for C
-----------
### About
CTestie is a C unit test framework that is supposed to be as minimal as possible. It's implemented entirely in a single header file without external dependencies. This offers fast compile and run times.  
  
[ctestie.h](https://github.com/stronka/CTestie/blob/master/src/include/ctestie.h)
### Features
* It's 18 LOC and two macros.
* There is no overhead in test files compared to some other "minimal" frameworks. You don't have to setup main or anything along that lines. You write tests and pass them to RUN. That's it.
* Test functions are actual functions and not macro magic. This should make them easier to read and navigate.
### Screenshots
![Alt text](/../screenshots/screenshots/success.png?raw=true "Success")
![Alt text](/../screenshots/screenshots/failure.png?raw=true "Failure")
### How to use
Place `ctestie.h` anywhere you want and a create test file that includes `ctestie.h` and tested code. It is recommended to use one test file per translation unit and treat it as a test suite.
For example to test function `bar` defined in `foo.c` you should create `test_foo.c` file that looks like so:

```C
#include "ctestie.h"
#include "foo.c"

TEST test_Bar_CaseZero_ReturnsZero(){
    int actual = bar(0);
    int expected = 0;
    ASSERT(actual == expected, "Fail. Got %d but expected %d", actual, expected);
}

TEST test_Bar_CaseMoreThanZero_ReturnsThatNumber(){
    int actual = bar(10);
    int expected = 10;
    ASSERT(actual == expected, "Fail. Got %d but expected %d", actual, expected);
}

TEST test_Bar_CaseLessThanZero_ReturnsZero(){
    int actual = bar(-5);
    int expected = 0;
    ASSERT(actual == expected, "Fail. Got %d but expected %d", actual, expected);
}

RUN(
    test_Bar_CaseZero_ReturnsZero,
    test_Bar_CaseMoreThanZero_ReturnsThatNumber,
    test_Bar_CaseLessThanZero_ReturnsZero
);
```
  
Test functions are defined by returning a TEST and containing a call to ASSERT. To run test functions pass pointers to them to
RUN.  
  
If you use make for your build targets then you would have this in your `Makefile`:   
```make
test_foo:
	$(CC) $(TEST_DIR)/test_foo.c $(FLAGS) -o $(TEST_DEST)/test_foo
	$(TEST_DEST)/test_foo
```
Then, to group tests, you may create another target that will contain all your test suites.  
```make
unit:
	test_foo
	test_baz
	test_some_other
```
### Examples
To build code from examples directory please refer to help provided in Makefile via command:  
  
`make help`
