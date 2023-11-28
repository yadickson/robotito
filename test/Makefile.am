EXTRA_DIST=position-mock.hpp macros-test.hpp
AM_CXXFLAGS=$(DEPENDENCIES_CFLAGS) $(TEST_DEPENDENCIES_CPPUTEST_CFLAGS) $(TEST_DEPENDENCIES_CPPNUIT_CFLAGS) -std=c++11 -Wall -g -O0 -coverage -I$(top_srcdir)/src

format-local:
	@echo "format test files"
	clang-format --sort-includes --style=GNU -i $(top_srcdir)/test/*.*pp

clean-local:
	$(RM) *.gcno
	$(RM) *.gcda
	$(RM) *.info
	$(RM) *.xml

if RUN_TESTS

noinst_PROGRAMS = robotito_test
robotito_test_SOURCES = test-runner.cpp position-test.cpp $(top_srcdir)/src/position.cpp robot-test.cpp $(top_srcdir)/src/robot.cpp
robotito_test_LDADD=$(DEPENDENCIES_LIBS) $(TEST_DEPENDENCIES_CPPUTEST_LIBS) $(TEST_DEPENDENCIES_CPPUNIT_LIBS)

if RUN_TESTS_WITH_CPPUTEST
test-local: robotito_test
	./robotito_test -c -v -ojunit
endif
	
if RUN_TESTS_WITH_CPPUNIT
test-local: robotito_test
	./robotito_test
endif

if RUN_COVERAGE
coverage-local: test-local
	lcov --directory . --capture --output-file lcov.info --include '*/src/*'
	genhtml --demangle-cpp -t robotito -o ../reports/coverage lcov.info

check-local: coverage-local

endif

endif
