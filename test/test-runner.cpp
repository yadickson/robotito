#include "macros-test.hpp"
#include <cstdlib>
#include <iostream>

int
main (int argc, char *argv[])
{
  srand ((unsigned)time (NULL));

#ifdef RUN_TESTS_WITH_CPPUTEST

  MockSupportPlugin mockSupport;
  TestRegistry::getCurrentRegistry ()->installPlugin (&mockSupport);

  return CommandLineTestRunner::RunAllTests (argc, argv);

#else

  CPPUNIT_NS::TestResult testresult;
  CPPUNIT_NS::TestResultCollector collectedresults;
  CPPUNIT_NS::BriefTestProgressListener progress;
  CPPUNIT_NS::TestRunner testrunner;

  testresult.addListener (&collectedresults);
  testresult.addListener (&progress);
  testrunner.addTest (
      CPPUNIT_NS::TestFactoryRegistry::getRegistry ().makeTest ());
  testrunner.run (testresult);

  CPPUNIT_NS::CompilerOutputter compileroutputter (&collectedresults,
                                                   std::cerr);
  compileroutputter.write ();

  std::ofstream xmlFileOut ("xunit.xml");
  CppUnit::XmlOutputter xmlOut (&collectedresults, xmlFileOut);
  xmlOut.write ();

  return collectedresults.wasSuccessful () ? 0 : 1;

#endif
}
