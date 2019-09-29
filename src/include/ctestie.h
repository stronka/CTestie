#ifndef __CTESTIE_H__
#define __CTESTIE_H__
#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>

typedef struct test_result {int result; const char *assertion; const char *message; char const *function;} TEST;
typedef TEST (*test_function)();
TEST __test_sentinel(){return (TEST){};};
char _buff[100];

#define ASSERT(assertion, message, ...) snprintf(_buff, 100, message, ##__VA_ARGS__); TEST _result = {assertion, #assertion, _buff, __FUNCTION__}; return _result
#define RUN(...) int main(){ \
		printf("\x1b[36m" "\n[CTestie] Running tests in: %s\n\n" "\x1b[0m", __FILE__ ); \
		TEST result; int passed = 0, run=0; test_function array[] = {__VA_ARGS__, __test_sentinel}; \
		int i; for (i=0; array[i] != __test_sentinel; ++i){ _EVAL(array[i]); } \
		printf(run-passed ? _FAIL_SUMMARY : _SUCCESS_SUMMARY, run, passed, run-passed); \
		return 0; }

#define _EVAL(test_case) result = test_case(); !(result.result) ? printf("[CTestie:Fail] %s\n Assertion: %s\n Message: %s\n\n", result.function, result.assertion, result.message) : ++passed; ++run

#define _SUCCESS_SUMMARY "\x1b[32m" "[CTestie:Summary] Tests finished successfully.\n Run: %d\n Passed: %d\n Failed: %d\n" "\x1b[0m"
#define _FAIL_SUMMARY "\x1b[31m" "[CTestie:Summary] Tests failed.\n Run: %d\n Passed: %d\n Failed: %d\n" "\x1b[0m"
#ifdef __cplusplus
}
#endif
#endif
