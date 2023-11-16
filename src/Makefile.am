EXTRA_DIST=position.hpp
AM_CXXFLAGS=$(DEPENDENCIES_CFLAGS)

bin_PROGRAMS = robotito
robotito_SOURCES = main.cpp position.cpp
robotito_LDADD=$(DEPENDENCIES_LIBS)

SOURSES=$(EXTRA_DIST) $(robotito_SOURCES)

format-local:
	@echo "format src files"
	clang-format --sort-includes --style=GNU -i $(top_srcdir)/src/*.*pp
