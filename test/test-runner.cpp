#include <cstdlib>
#include <ctime>

#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestRegistry.h>
#include <CppUTestExt/MockSupportPlugin.h>

auto
main (int argc, char *argv[]) -> int
{
  srand ((unsigned)time (nullptr));

  MockSupportPlugin mockPlugin;
  TestRegistry::getCurrentRegistry ()->installPlugin (&mockPlugin);
  const int response = CommandLineTestRunner::RunAllTests (argc, argv);
  TestRegistry::getCurrentRegistry ()->resetPlugins ();
  return response;
}
