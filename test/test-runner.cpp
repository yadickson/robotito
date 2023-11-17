#include <CppUTest/CommandLineTestRunner.h>
#include <cstdlib>

int
main (int argc, char *argv[])
{
  srand ((unsigned)time (NULL));
  return CommandLineTestRunner::RunAllTests (argc, argv);
}
