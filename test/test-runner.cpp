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

using namespace CPPUNIT_NS;
using namespace std;

int
main (int argc, char *argv[])
{
  TestResult testresult;
  TestResultCollector collectedresults;
  BriefTestProgressListener progress;
  TestRunner testrunner;

  Test *test = TestFactoryRegistry::getRegistry ().makeTest ();

  testresult.addListener (&collectedresults);
  testresult.addListener (&progress);
  testrunner.addTest (test);
  testrunner.run (testresult);

  CompilerOutputter compileroutputter (&collectedresults, cerr);
  compileroutputter.write ();

  ofstream xmlFileOut ("xunit.xml");
  XmlOutputter xmlOut (&collectedresults, xmlFileOut);
  xmlOut.write ();

  return collectedresults.wasSuccessful () ? 0 : 1;
}
