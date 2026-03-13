BLUE := $(shell tput -Txterm setaf 4)\\n
GREEN := $(shell tput -Txterm setaf 2)\\n
NC := $(shell tput -Txterm sgr0)\\n\\n

EXTRA_DIST = position-mock.hpp macros-test.hpp

SRC_FILES = \
	$(top_srcdir)/src/robot.hpp \
	$(top_srcdir)/src/robot.cpp \
	$(top_srcdir)/src/position.hpp \
	$(top_srcdir)/src/position.cpp
	$(top_srcdir)/src/display.hpp \
	$(top_srcdir)/src/display.cpp
	$(top_srcdir)/src/game.hpp \
	$(top_srcdir)/src/game.cpp
	$(top_srcdir)/src/keyboard.hpp \
	$(top_srcdir)/src/keyboard.cpp
	$(top_srcdir)/src/table.hpp \
	$(top_srcdir)/src/table.cpp

TEST_FILES = \
	$(top_srcdir)/test/test-runner.cpp \
	$(top_srcdir)/test/position-mock.cpp \
	$(top_srcdir)/test/robot-test.cpp \
	$(top_srcdir)/test/position-test.cpp

format-local: $(EXTRA_DIST) $(TEST_FILES)
	@printf "$(BLUE)Formating test files.${NC}"
if RUN_TIDY
	clang-tidy --checks="cppcoreguidelines-*,modernize-*,-cppcoreguidelines-special-member-functions,-cppcoreguidelines-macro-usage" --fix $^ -- $(STDCXX_CXXFLAGS) -x c++ -I$(top_srcdir)/src
endif
if RUN_FORMAT
	clang-format --sort-includes --style=GNU -i $^
endif
	@printf "$(GREEN)OK${NC}"

lint-local: $(EXTRA_DIST) $(TEST_FILES)
	@printf "$(BLUE)Checking static code test files.${NC}"
if RUN_TIDY
	clang-tidy --checks="cppcoreguidelines-*,modernize-*,-cppcoreguidelines-special-member-functions,-cppcoreguidelines-macro-usage" $^ -- $(STDCXX_CXXFLAGS) -x c++ -I$(top_srcdir)/src
endif
if RUN_CPPCHECK
	cppcheck $(top_srcdir)/test --enable=all --library=std -I$(top_srcdir)/src --suppress=missingIncludeSystem
endif
	@printf "$(GREEN)OK${NC}"

if RUN_TESTS

LIBSTDCPP := -lstdc++
TEST_DEPENDENCIES_CPPUTEST_SORT_LIBS = $(subst $(LIBSTDCPP), ,$(TEST_DEPENDENCIES_CPPUTEST_LIBS) )

noinst_PROGRAMS = robotito_test
robotito_test_SOURCES = $(SRC_FILES) $(TEST_FILES)
robotito_test_CXXFLAGS = $(DEPENDENCIES_CFLAGS) $(TEST_DEPENDENCIES_CPPUTEST_CFLAGS) $(CUSTOM_CXXFLAGS) -g -O0 -fprofile-arcs -ftest-coverage --coverage -I$(top_srcdir)/src
robotito_test_LDADD = $(DEPENDENCIES_LIBS) $(TEST_DEPENDENCIES_CPPUTEST_SORT_LIBS) $(LIBSTDCPP)

test-local: robotito_test
	@printf "${BLUE}Running tests.${NC}"
	./robotito_test -c -v -ojunit
	@printf "$(GREEN)OK${NC}"

if RUN_COVERAGE

coverage-local: test-local
	@printf "${BLUE}Running coverage.${NC}"
	lcov -c -d $(top_srcdir)/src --output-file $(top_srcdir)/lcov.info
	genhtml --demangle-cpp -t robotito -o $(top_srcdir)/reports/coverage $(top_srcdir)/lcov.info
	@printf "$(GREEN)OK${NC}"

endif

endif

check-local: lint-local

CLEAN_FILES = gcov gcno gcda info xml

clean-local:
	$(foreach file, $(CLEAN_FILES), $(RM) *.$(file))