#include <cstdlib>
#include <iostream>

#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>
#include <CppUTest/TestRegistry.h>
#include <CppUTestExt/MockSupport.h>
#include <CppUTestExt/MockSupportPlugin.h>

auto
main (int argc, char *argv[]) -> int
{
  srand ((unsigned)time (nullptr));

  MockSupportPlugin mockSupport;
  TestRegistry::getCurrentRegistry ()->installPlugin (&mockSupport);

  return CommandLineTestRunner::RunAllTests (argc, argv);
}
