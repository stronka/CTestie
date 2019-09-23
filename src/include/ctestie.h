#ifndef __CTESTIE_H__
#define __CTESTIE_H__
#include <stdio.h>
#define ASSERT(OPERATION, MESSAGE) TEST result = {OPERATION, #OPERATION, MESSAGE, __FUNCTION__}; return result
#define RUN(...) int main(){printf("\n[CTestie] Running tests in: %s\n\n", __FILE__ );TEST result; int passed = 0, run=0; test_function array[] = {__VA_ARGS__, __test_sentinel};\
for (int i=0; array[i] != __test_sentinel; ++i){_eval(array[i]);} printf(run-passed ? _fail_summary : _success_summary, run, passed, run-passed);return 0;}
#define _eval(TEST_CASE) result = TEST_CASE(); !(result.result) ? printf("[CTestie:Fail] %s\n Assertion: %s\n Message: %s\n", result.function, result.assertion, result.message) : ++passed; ++run
#define R "\x1b[31m"
#define G "\x1b[32m"
#define N "\x1b[0m"
#define _summary "\n[CTestie:Summary] Tests finished.\n Run: %d\n Passed: %d\n Failed: %d\n"
#define _success_summary G _summary N
#define _fail_summary R _summary N
typedef struct test_result{int result; char *assertion; char *message; char const *function;} TEST; typedef TEST(*test_function)(); TEST __test_sentinel(){return (TEST){};};
#endif
