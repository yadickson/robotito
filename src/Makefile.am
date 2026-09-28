BLUE := $(shell tput -Txterm setaf 4)\\n
GREEN := $(shell tput -Txterm setaf 2)\\n
NC := $(shell tput -Txterm sgr0)\\n\\n

EXTRA_DIST = keyboard.hpp table.hpp position.hpp robot.hpp game.hpp display.hpp

noinst_LTLIBRARIES = librobotito.la

librobotito_la_SOURCES = position.cpp robot.cpp keyboard.cpp game.cpp table.cpp display.cpp
librobotito_la_CXXFLAGS = $(DEPENDENCIES_CFLAGS) $(CUSTOM_CXXFLAGS)
librobotito_la_LIBADD = $(DEPENDENCIES_LIBS)

bin_PROGRAMS = robotito
robotito_SOURCES = main.cpp
robotito_CXXFLAGS = $(CUSTOM_CXXFLAGS)
robotito_LDADD = librobotito.la

SOURSES = $(EXTRA_DIST) $(robotito_SOURCES)

format-local: $(SOURSES)
	@printf "${BLUE}Formating src files.${NC}"
if RUN_TIDY
	clang-tidy --checks="cppcoreguidelines-*,modernize-*,-cppcoreguidelines-special-member-functions,misc-include-cleaner, -cppcoreguidelines-avoid-magic-numbers, -readability-magic-numbers" --fix $^ -- $(STDCXX_CXXFLAGS) -x c++
endif
if RUN_FORMAT
	clang-format --sort-includes --style=GNU -i $^
endif
	@printf "$(GREEN)OK${NC}"

lint-local: $(SOURSES)
	@printf "${BLUE}Checking static code src files.${NC}"
if RUN_TIDY
	clang-tidy --checks="cppcoreguidelines-*,modernize-*,-cppcoreguidelines-special-member-functions,misc-include-cleaner, -cppcoreguidelines-avoid-magic-numbers, -readability-magic-numbers" $^ -- $(STDCXX_CXXFLAGS) -x c++
endif
if RUN_CPPCHECK
	cppcheck $(top_srcdir)/src --enable=all --library=std -I$(top_srcdir)/src --suppress=missingIncludeSystem
endif
	@printf "$(GREEN)OK${NC}"

check-local: lint-local

CLEAN_FILES = gcov gcno gcda

clean-local:
	$(foreach file, $(CLEAN_FILES), $(RM) *.$(file))