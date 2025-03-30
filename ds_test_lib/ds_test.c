#include <stdio.h>
#include <stdlib.h>
#include "ds_test.h"

static TestCase test_registry[MAX_TESTS];
static int test_registry_count = 0;

void assert_equal(const int expected, const int actual) {
    if (expected != actual) {
        fprintf(stderr, "Expected %d, but got %d\n", expected, actual);
        exit(1);
    }
}

void assert_true(const bool condition) {
    if (!condition) {
        fprintf(stderr, "Expected condition to be true.\n");
        exit(1);
    }
}

void assert_false(const bool condition) {
    if (condition) {
        fprintf(stderr, "Expected condition to be false.\n");
        exit(1);
    }
}

void register_test(const TestFunction fn, const char* name) {
    if (test_registry_count >= 100) {
        fprintf(stderr, "Maximum number of tests reached.\n");
        exit(1);
    }

    test_registry[test_registry_count].name = name;
    test_registry[test_registry_count].test_function = fn;
    test_registry_count++;
}

void run_tests() {
    for (int i = 0; i < test_registry_count; i++) {
        printf("Running test: %s...\n", test_registry[i].name);
        test_registry[i].test_function();
    }
    printf("All tests passed!\n");
}
