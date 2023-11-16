EXTRA_DIST=position-test.hpp
AM_CXXFLAGS=$(DEPENDENCIES_CFLAGS) $(TEST_DEPENDENCIES_CFLAGS) -std=c++11 -Wall -g -O0 -coverage -I$(top_srcdir)/src

noinst_PROGRAMS = robotito_test
robotito_test_SOURCES = test-runner.cpp position-test.cpp $(top_srcdir)/src/position.cpp
robotito_test_LDADD=$(DEPENDENCIES_LIBS) $(TEST_DEPENDENCIES_LIBS)

clean-local:
	$(RM) *.gcno
	$(RM) *.gcda
	$(RM) *.info
	$(RM) *.xml

test-local: robotito_test
	./robotito_test

coverage-local: test-local
	lcov --directory . --capture --output-file lcov.info --include '*/src/*'

genhtml-local:
	genhtml --demangle-cpp -t robotito -o ../reports/coverage lcov.info


check-local: coverage-local genhtml-local
