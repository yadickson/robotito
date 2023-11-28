AC_PREREQ(2.57)
AC_INIT([robotito], [0.0.1], [yadickson@gmail.com])

AM_INIT_AUTOMAKE([gnu])

AC_LANG(C++)
AC_PROG_CXX
AC_PROG_INSTALL

AM_EXTRA_RECURSIVE_TARGETS([
	test
	coverage
	format
	cppcheck
	memcheck
])

AC_CONFIG_FILES([
	Makefile
	src/Makefile
	test/Makefile
])

PKG_PROG_PKG_CONFIG

PKG_CHECK_EXISTS([ncursesw], [], [AC_MSG_ERROR [ncursesw is required]])
PKG_CHECK_EXISTS([cpputest], [], [AC_MSG_ERROR [cpputest is required]])

AC_CHECK_PROGS([LCOV], [lcov], [yes], [])
AC_CHECK_PROGS([GENHTML], [genhtml], [yes], [])
AC_CHECK_PROGS([CPPCHECK], [cppcheck], [yes], [])

AS_VAR_IF([LCOV], [lcov], [], [AC_MSG_ERROR([lcov is required])])
AS_VAR_IF([GENHTML], [genhtml], [], [AC_MSG_ERROR([genhtml is required])])
AS_VAR_IF([CPPCHECK], [cppcheck], [], [AC_MSG_ERROR([cppcheck is required])])

PKG_CHECK_MODULES([DEPENDENCIES], [ncursesw])
PKG_CHECK_MODULES([TEST_DEPENDENCIES], [cpputest])
      
AC_CHECK_HEADER([ncurses.h])
AC_CHECK_HEADER([clocale])
AC_CHECK_HEADER([iostream])
AC_CHECK_HEADER([cstdlib])
AC_CHECK_HEADER([cstddef])

AC_OUTPUT
