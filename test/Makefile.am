AM_CXXFLAGS=$(DEPENDENCIES_CFLAGS) $(TEST_DEPENDENCIES_CFLAGS) -std=c++11 -Wall -g -O0 -coverage -I../src

noinst_PROGRAMS = robotito_test
robotito_test_SOURCES = test-runner.cpp position-test.cpp ../src/position.cpp
robotito_test_LDADD=$(DEPENDENCIES_LIBS) $(TEST_DEPENDENCIES_LIBS)


test-local: robotito_test
	./robotito_test
	lcov --directory . --capture --output-file lcov.info --include '*/src/*'
	genhtml --demangle-cpp -t robotito -o ../reports/coverage lcov.info