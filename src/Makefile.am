BLUE  := $(shell tput -Txterm setaf 4)\\n
GREEN := $(shell tput -Txterm setaf 2)\\n
NC    := $(shell tput -Txterm sgr0)\\n

EXTRA_DIST = keyboard.hpp table.hpp position.hpp robot.hpp game.hpp display.hpp

bin_PROGRAMS = robotito
robotito_SOURCES = main.cpp position.cpp robot.cpp keyboard.cpp game.cpp table.cpp display.cpp
robotito_CXXFLAGS = $(DEPENDENCIES_CFLAGS) $(AM_CXXFLAGS)
robotito_LDADD = $(DEPENDENCIES_LIBS)

SOURSES=$(EXTRA_DIST) $(robotito_SOURCES)

format-local:
	@echo -e "${BLUE}Formating src files.${NC}"
	clang-format --sort-includes --style=GNU -i $(top_srcdir)/src/*.*pp
	@echo -e "$(GREEN)OK${NC}"

lint-local: $(SOURSES)
	@echo -e "${BLUE}Checking static code src files.${NC}"
	clang-tidy $^ -- $(DEPENDENCIES_CFLAGS) $(AM_CXXFLAGS)
	@echo -e "$(GREEN)OK${NC}"

cppcheck-local:
	@echo -e "${BLUE}Running cppcheck src files.${NC}"
	cppcheck $(top_srcdir)/src --enable=all --language=c++ --suppress=missingIncludeSystem
	@echo -e "$(GREEN)OK${NC}"

check-local: lint-local cppcheck-local

CLEAN_FILES = gcov gcno gcda

clean-local:
	$(foreach file, $(CLEAN_FILES), $(RM) *.$(file))
