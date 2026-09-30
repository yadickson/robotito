BLUE := $(shell tput -Txterm setaf 4)\\n
GREEN := $(shell tput -Txterm setaf 2)\\n
NC := $(shell tput -Txterm sgr0)\\n\\n

EXTRA_DIST = \
    $(top_srcdir)/src/position.hpp \
    $(top_srcdir)/src/robot.hpp  \
    $(top_srcdir)/src/keyboard.hpp  \
    $(top_srcdir)/src/game.hpp \
    $(top_srcdir)/src/table.hpp \
    $(top_srcdir)/src/display.hpp

SOURCE_FILES = \
    $(top_srcdir)/src/position.cpp \
    $(top_srcdir)/src/robot.cpp  \
    $(top_srcdir)/src/keyboard.cpp  \
    $(top_srcdir)/src/game.cpp \
    $(top_srcdir)/src/table.cpp \
    $(top_srcdir)/src/display.cpp

noinst_LTLIBRARIES = librobotito.la

librobotito_la_SOURCES = $(SOURCE_FILES)
librobotito_la_CXXFLAGS = $(DEPENDENCIES_CFLAGS) $(CUSTOM_CXXFLAGS)
librobotito_la_LIBADD = $(DEPENDENCIES_LIBS)

bin_PROGRAMS = robotito
robotito_SOURCES = main.cpp
robotito_CXXFLAGS = $(DEPENDENCIES_CFLAGS) $(CUSTOM_CXXFLAGS)
robotito_LDADD = $(DEPENDENCIES_LIBS) librobotito.la

SOURSES = $(EXTRA_DIST) $(SOURCE_FILES)

format-local: $(SOURSES)
	@printf "${BLUE}Formating src files.${NC}"
if RUN_LINT
	clang-tidy --checks="cppcoreguidelines-*,modernize-*,-cppcoreguidelines-special-member-functions,misc-include-cleaner, -cppcoreguidelines-avoid-magic-numbers, -readability-magic-numbers" --fix $^ -- $(STDCXX_CXXFLAGS) -x c++ -I$(top_srcdir)/src
endif
if RUN_FORMAT
	clang-format --sort-includes --style=GNU -i $^
endif
	@printf "$(GREEN)OK${NC}"

lint-local: $(SOURSES)
	@printf "${BLUE}Checking static code src files.${NC}"
if RUN_LINT
	clang-tidy --checks="cppcoreguidelines-*,modernize-*,-cppcoreguidelines-special-member-functions,misc-include-cleaner, -cppcoreguidelines-avoid-magic-numbers, -readability-magic-numbers" $^ -- $(STDCXX_CXXFLAGS) -x c++ -I$(top_srcdir)/src
endif
if RUN_CPPCHECK
	cppcheck $(top_srcdir)/src --enable=all --library=std -I$(top_srcdir)/src --suppress=missingIncludeSystem
endif
	@printf "$(GREEN)OK${NC}"

check-local: lint-local

CLEAN_FILES = gcov gcno gcda

clean-local:
	$(foreach file, $(CLEAN_FILES), $(RM) *.$(file))