#ifndef __CTESTIE_H__
#define __CTESTIE_H__
#include <stdio.h>
#define ASSERT(OPERATION, MESSAGE, ...) snprintf(_buff, 100, MESSAGE, ##__VA_ARGS__); TEST result = {OPERATION, #OPERATION, _buff, __FUNCTION__}; return result
#define RUN(...) int main(){printf(_C"\n[CTestie] Running tests in: %s\n\n"_N, __FILE__ );TEST result; int passed = 0, run=0; test_function array[] = {__VA_ARGS__, __test_sentinel};\
int i;for (i=0; array[i] != __test_sentinel; ++i){_eval(array[i]);} printf(run-passed ? _fail_summary : _success_summary, run, passed, run-passed);return 0;}
#define _eval(TEST_CASE) result = TEST_CASE(); !(result.result) ? printf("[CTestie:Fail] %s\n Assertion: %s\n Message: %s\n\n", result.function, result.assertion, result.message) : ++passed; ++run
#define _R "\x1b[31m"
#define _G "\x1b[32m"
#define _C "\x1b[36m"
#define _N "\x1b[0m"
#define _summary "[CTestie:Summary] Tests finished.\n Run: %d\n Passed: %d\n Failed: %d\n"
#define _success_summary _G _summary _N
#define _fail_summary _R _summary _N
char _buff[100]; typedef struct test_result{int result; char *assertion; char *message; char const *function;} TEST; typedef TEST(*test_function)(); TEST __test_sentinel(){return (TEST){};};
#endif
