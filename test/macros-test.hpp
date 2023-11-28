#pragma once

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#ifdef RUN_TESTS_WITH_CPPUTEST

#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>
#include <CppUTest/TestRegistry.h>
#include <CppUTestExt/MockSupport.h>
#include <CppUTestExt/MockSupportPlugin.h>

#define MACRO_TEST_CLASS(input) TEST_GROUP (input)

#define MACRO_TEST_SETUP() TEST_SETUP ()

#define MACRO_TEST_TEARDOWN() TEST_TEARDOWN ()

#define MACRO_TEST_CLEAR_MOCK() mock ().clear ()

#define MACRO_TEST_SUITE_START(input)

#define MACRO_TEST_SUITE_TEST(method)

#define MACRO_TEST_SUITE_END()

#define MACRO_TEST_REGISTRATION(input)

#define MACRO_TEST_METHOD(method)

#define MACRO_TEST(input, method) TEST (input, method)

#define MACRO_CHECK_EQUAL(expected, actual) CHECK_EQUAL (expected, actual)

#else

#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/XmlOutputter.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TextTestRunner.h>

#define MACRO_TEST_CLASS(input)                                               \
  class CppUnitTest##input##Test : public CPPUNIT_NS::TestFixture

#define MACRO_TEST_SETUP() virtual void setUp ()

#define MACRO_TEST_TEARDOWN() virtual void tearDown ()

#define MACRO_TEST_CLEAR_MOCK()

#define MACRO_TEST_SUITE_START(input)                                         \
  CPPUNIT_TEST_SUITE (CppUnitTest##input##Test)

#define MACRO_TEST_SUITE_TEST(method) CPPUNIT_TEST (method)

#define MACRO_TEST_SUITE_END() CPPUNIT_TEST_SUITE_END ()

#define MACRO_TEST_REGISTRATION(input)                                        \
  CPPUNIT_TEST_SUITE_REGISTRATION (CppUnitTest##input##Test)

#define MACRO_TEST_METHOD(method) void method ()

#define MACRO_TEST(input, method) void CppUnitTest##input##Test ::method ()

#define MACRO_CHECK_EQUAL(expected, actual)                                   \
  CPPUNIT_ASSERT_EQUAL (expected, actual)

#endif
