BLUE := $(shell tput -Txterm setaf 4)\\n
GREEN := $(shell tput -Txterm setaf 2)\\n
NC := $(shell tput -Txterm sgr0)\\n\\n

EXTRA_DIST = position-mock.hpp

TEST_FILES = \
	$(top_srcdir)/test/faker-cxx.hpp \
	$(top_srcdir)/test/faker-cxx.cpp \
	$(top_srcdir)/test/test-runner.cpp \
	$(top_srcdir)/test/position-mock.cpp \
	$(top_srcdir)/test/robot-test.cpp \
	$(top_srcdir)/test/position-test.cpp

format-local: $(EXTRA_DIST) $(TEST_FILES)
	@printf "$(BLUE)Formating test files.${NC}"
if RUN_TIDY
	clang-tidy --checks="cppcoreguidelines-*,modernize-*,-cppcoreguidelines-special-member-functions,-cppcoreguidelines-macro-usage,misc-include-cleaner, -cppcoreguidelines-avoid-magic-numbers, -readability-magic-numbers" --fix $^ -- $(STDCXX_CXXFLAGS) -x c++ -I$(top_srcdir)/src
endif
if RUN_FORMAT
	clang-format --sort-includes --style=GNU -i $^
endif
	@printf "$(GREEN)OK${NC}"

lint-local: $(EXTRA_DIST) $(TEST_FILES)
	@printf "$(BLUE)Checking static code test files.${NC}"
if RUN_TIDY
	clang-tidy --checks="cppcoreguidelines-*,modernize-*,-cppcoreguidelines-special-member-functions,-cppcoreguidelines-macro-usage,misc-include-cleaner, -cppcoreguidelines-avoid-magic-numbers, -readability-magic-numbers" $^ -- $(STDCXX_CXXFLAGS) -x c++ -I$(top_srcdir)/src
endif
if RUN_CPPCHECK
	cppcheck $(top_srcdir)/test --enable=all --library=std -I$(top_srcdir)/src --suppress=missingIncludeSystem --suppress=variableScope
endif
	@printf "$(GREEN)OK${NC}"

if RUN_TESTS

build-external:
	$(MAKE) -C $(top_builddir)/src

check_PROGRAMS = test_robotito
test_robotito_SOURCES = $(TEST_FILES)
test_robotito_CXXFLAGS = $(DEPENDENCIES_CFLAGS) $(TEST_DEPENDENCIES_CPPUTEST_CFLAGS) $(CUSTOM_CXXFLAGS) -g -O0 -fprofile-arcs -ftest-coverage --coverage -I$(top_srcdir)/src
test_robotito_LDADD = $(DEPENDENCIES_LIBS) $(TEST_DEPENDENCIES_CPPUTEST_LIBS) $(top_builddir)/src/librobotito.la

test-dependencies: | build-external
test-local: test-dependencies test_robotito
	@printf "${BLUE}Running tests.${NC}"
	./test_robotito -c -v -ojunit
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