CTestie
===========
Minimal unit test framework for C
-----------
### About
CTestie is a C test framework that is supposed to be as minimal as possible. It's implemented entirely in a single header file. This offers fast compile and run times. 
### How to use
Place `ctestie.h` anywhere you want and a create test file that includes `ctestie.h` and tested code. It is recommended to use one test file per translation unit and treat it as a test suite.
For example to test function `bar` defined in `foo.c` you should create `test_foo.c` file that looks like so:

```C
#include "ctestie.h"
#include "foo.c"

TEST test_bar(){
    int actual = bar();
    int expected = 5;
    ASSERT(actual == expected, "Fail. Got %d but expected %d", actual, expected);
}

RUN(test_bar);
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
