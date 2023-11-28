EXTRA_DIST=keyboard.hpp table.hpp position.hpp robot.hpp game.hpp display.hpp
AM_CXXFLAGS=$(DEPENDENCIES_CFLAGS)

bin_PROGRAMS = robotito
robotito_SOURCES = main.cpp position.cpp robot.cpp keyboard.cpp game.cpp table.cpp display.cpp
robotito_LDADD=$(DEPENDENCIES_LIBS)

SOURSES=$(EXTRA_DIST) $(robotito_SOURCES)

format-local:
	@echo "format src files"
	clang-format --sort-includes --style=GNU -i $(top_srcdir)/src/*.*pp

cppcheck-local:
	cppcheck $(top_srcdir)/src --enable=all --language=c++ --suppress=missingIncludeSystem

check-local: cppcheck-local
