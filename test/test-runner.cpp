#include <cstdlib>
#include <iostream>

#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestHarness.h>
#include <CppUTest/TestRegistry.h>
#include <CppUTestExt/MockSupport.h>
#include <CppUTestExt/MockSupportPlugin.h>

int
main (int argc, char *argv[])
{
  srand ((unsigned)time (NULL));

  MockSupportPlugin mockSupport;
  TestRegistry::getCurrentRegistry ()->installPlugin (&mockSupport);

  return CommandLineTestRunner::RunAllTests (argc, argv);
}
