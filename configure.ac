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

AC_CHECK_PROGS([CPPCHECK], [cppcheck], [yes], [])

AS_VAR_IF([CPPCHECK], [cppcheck], [], [AC_MSG_ERROR([cppcheck is required])])

PKG_CHECK_MODULES([DEPENDENCIES], [ncursesw])
      
AC_MSG_CHECKING([Checking if tests should be enabled])
AC_ARG_ENABLE([tests],[AS_HELP_STRING([--disable-tests], [Disable tests])], [])

test "x$enable_tests" = xno || enable_tests=yes
AC_MSG_RESULT($enable_tests)

AM_CONDITIONAL(RUN_TESTS, [test "x$enable_tests" = xyes])

PKG_CHECK_EXISTS([ncursesw], [], [AC_MSG_ERROR [ncursesw is required]])

if test "x$enable_tests" = xyes; then
	PKG_CHECK_EXISTS([cpputest], [], [AC_MSG_ERROR [cpputest is required]])

	AC_CHECK_PROGS([LCOV], [lcov], [yes], [])
	AC_CHECK_PROGS([GENHTML], [genhtml], [yes], [])

	AS_VAR_IF([LCOV], [lcov], [], [AC_MSG_ERROR([lcov is required])])
	AS_VAR_IF([GENHTML], [genhtml], [], [AC_MSG_ERROR([genhtml is required])])

	PKG_CHECK_MODULES([TEST_DEPENDENCIES], [cpputest])
fi

AC_CHECK_HEADER([ncurses.h])
AC_CHECK_HEADER([clocale])
AC_CHECK_HEADER([iostream])
AC_CHECK_HEADER([cstdlib])
AC_CHECK_HEADER([cstddef])

AC_OUTPUT
