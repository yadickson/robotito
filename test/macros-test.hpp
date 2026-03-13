#ifndef MACROS_TEST_HPP_
#define MACROS_TEST_HPP_

#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>
#include <CppUTest/TestRegistry.h>
#include <CppUTestExt/MockSupport.h>
#include <CppUTestExt/MockSupportPlugin.h>

#define MACRO_TEST_CLASS(input) TEST_GROUP (input)

#define MACRO_TEST_SETUP() TEST_SETUP ()

#define MACRO_TEST_TEARDOWN() TEST_TEARDOWN ()

#define MACRO_TEST_CLEAR_MOCK() mock ().clear ()

#define MACRO_TEST(input, method) TEST (input, method)

#define MACRO_CHECK_EQUAL(expected, actual) CHECK_EQUAL (expected, actual)

#endif // MACROS_TEST_HPP_
