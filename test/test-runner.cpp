#include <cstdlib>
#include <ctime>

#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTest/TestRegistry.h>
#include <CppUTestExt/MockSupportPlugin.h>

#ifdef IS_WINDOWS
#include <CppUTest/MemoryLeakWarningPlugin.h>
#endif

auto
main (int argc, char *argv[]) -> int
{
  srand ((unsigned)time (nullptr));

#ifdef IS_WINDOWS
  MemoryLeakWarningPlugin::turnOffNewDeleteOverloads ();
#endif

  MockSupportPlugin mockPlugin;
  TestRegistry::getCurrentRegistry ()->installPlugin (&mockPlugin);
  const int response = CommandLineTestRunner::RunAllTests (argc, argv);
  TestRegistry::getCurrentRegistry ()->resetPlugins ();
  return response;
}
