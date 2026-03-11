EXTRA_DIST = position-mock.hpp macros-test.hpp

format-local:
	@echo "format test files"
	clang-format --sort-includes --style=GNU -i $(top_srcdir)/test/*.*pp

if RUN_TESTS

SOURCE_FILES = \
	$(top_srcdir)/src/robot.hpp \
	$(top_srcdir)/src/robot.cpp \
	$(top_srcdir)/src/position.hpp \
	$(top_srcdir)/src/position.cpp

TEST_FILES = \
	$(top_srcdir)/test/test-runner.cpp \
	$(top_srcdir)/test/robot-test.cpp \
	$(top_srcdir)/test/position-test.cpp

noinst_PROGRAMS = robotito_test
robotito_test_SOURCES = $(SOURCE_FILES) $(TEST_FILES)
robotito_test_CXXFLAGS = $(DEPENDENCIES_CFLAGS) $(TEST_DEPENDENCIES_CPPUTEST_CFLAGS) -std=c++11 -Wall -g -O0 -fprofile-arcs -ftest-coverage --coverage -I$(top_srcdir)/src
robotito_test_LDADD = $(DEPENDENCIES_LIBS) $(TEST_DEPENDENCIES_CPPUTEST_LIBS)

test-local: robotito_test
	./robotito_test -c -v -ojunit

if RUN_COVERAGE

coverage-local: test-local
	lcov -c -d ../src --output-file lcov.info
	genhtml --demangle-cpp -t robotito -o ../reports/coverage lcov.info

check-local: coverage-local

endif

endif

CLEAN_FILES = gcov gcno gcda info xml

clean-local:
	$(foreach file, $(CLEAN_FILES), $(RM) *.$(file))
