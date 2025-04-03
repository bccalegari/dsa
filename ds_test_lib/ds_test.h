#ifndef DS_TEST_H
#define DS_TEST_H

#include <stdbool.h>

#define MAX_TESTS 100

typedef void (*TestFunction)(void);

typedef struct {
    const char* name;
    TestFunction test_function;
} TestCase;

void assert_equal(int expected, int actual);
void assert_true(bool condition);
void assert_false(bool condition);
void assert_null(const void* ptr);
void assert_not_null(const void* ptr);
void register_test(TestFunction fn, const char* name);
void run_tests();

#endif
