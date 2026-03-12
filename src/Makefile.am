BLUE := $(shell tput -Txterm setaf 4)\\n
GREEN := $(shell tput -Txterm setaf 2)\\n
NC := $(shell tput -Txterm sgr0)\\n\\n

EXTRA_DIST = keyboard.hpp table.hpp position.hpp robot.hpp game.hpp display.hpp

bin_PROGRAMS = robotito
robotito_SOURCES = main.cpp position.cpp robot.cpp keyboard.cpp game.cpp table.cpp display.cpp
robotito_CXXFLAGS = $(DEPENDENCIES_CFLAGS) $(AM_CXXFLAGS)
robotito_LDADD = $(DEPENDENCIES_LIBS)

SOURSES = $(EXTRA_DIST) $(robotito_SOURCES)

if RUN_FORMAT

format-local:
	@printf "${BLUE}Formating src files.${NC}"
	clang-format --sort-includes --style=GNU -i $(top_srcdir)/src/*.*pp
	@printf "$(GREEN)OK${NC}"

endif

if RUN_LINT

lint-local: $(SOURSES)
	@printf "${BLUE}Checking static code src files.${NC}"
	clang-tidy $^ -- $(DEPENDENCIES_CFLAGS) $(AM_CXXFLAGS)
	@printf "$(GREEN)OK${NC}"

endif

if RUN_CPPCHECK

cppcheck-local:
	@printf "${BLUE}Running cppcheck src files.${NC}"
	cppcheck $(top_srcdir)/src --enable=all --language=c++ --suppress=missingIncludeSystem
	@printf "$(GREEN)OK${NC}"

endif

CLEAN_FILES = gcov gcno gcda

clean-local:
	$(foreach file, $(CLEAN_FILES), $(RM) *.$(file))