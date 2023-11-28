AC_PREREQ(2.57)
AC_INIT([robotito], [0.0.1], [yadickson@gmail.com])

AM_INIT_AUTOMAKE([gnu])

AC_LANG(C++)
AC_PROG_CXX
AC_PROG_INSTALL
AC_CONFIG_HEADERS([config.h])

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
      
AC_MSG_CHECKING([tests enabled])
AC_ARG_ENABLE([tests],[AS_HELP_STRING([--disable-tests], [Disable tests])], [enable_tests=no], [enable_tests=yes])
AC_MSG_RESULT($enable_tests)

PKG_CHECK_EXISTS([ncursesw], [], [AC_MSG_ERROR [ncursesw is required]])

if test "x$enable_tests" = xyes; then

	AC_MSG_CHECKING([tests with cpputest])
	AC_ARG_ENABLE([cpputest],[AS_HELP_STRING([--disable-cpputest], [Disable tests with cpputest])], [enable_cpputest=no], [enable_cpputest=yes])
	AC_MSG_RESULT($enable_cpputest)

	if test "x$enable_cpputest" = xno ; then enable_cppunit=yes; fi

	AC_MSG_CHECKING([tests with cppunit])
	AC_ARG_ENABLE([cppunit],[AS_HELP_STRING([--enable-cppunit], [Enable tests with cppunit])], [enable_cppunit=yes], [enable_cppunit=no])
	AC_MSG_RESULT($enable_cppunit)

	if test "x$enable_cppunit" = xno ; then enable_cpputest=yes; fi

	if test "x$enable_cpputest" = xyes; then
		AC_DEFINE([RUN_TESTS_WITH_CPPUTEST], [1], [RUN_TESTS_WITH_CPPUTEST])
		PKG_CHECK_EXISTS([cpputest], [], [AC_MSG_ERROR [cpputest is required]])
		PKG_CHECK_MODULES([TEST_DEPENDENCIES_CPPUTEST], [cpputest])
	else
		AC_DEFINE([RUN_TESTS_WITH_CPPUNIT], [1], [RUN_TESTS_WITH_CPPUNIT])
		PKG_CHECK_EXISTS([cppunit], [], [AC_MSG_ERROR [cppunit is required]])
		PKG_CHECK_MODULES([TEST_DEPENDENCIES_CPPUNIT], [cppunit])
	fi

	AC_MSG_CHECKING([coverage])
	AC_ARG_ENABLE([coverage],[AS_HELP_STRING([--disable-coverage], [Disable coverage])], [enable_coverage=no], [enable_coverage=yes])
	AC_MSG_RESULT($enable_coverage)

	if test "x$enable_coverage" = xyes; then
		AC_CHECK_PROGS([LCOV], [lcov], [yes], [])
		AC_CHECK_PROGS([GENHTML], [genhtml], [yes], [])
	
		AS_VAR_IF([LCOV], [lcov], [], [AC_MSG_ERROR([lcov is required])])
		AS_VAR_IF([GENHTML], [genhtml], [], [AC_MSG_ERROR([genhtml is required])])
	fi
fi

AC_CHECK_HEADER([ncurses.h])
AC_CHECK_HEADER([clocale])
AC_CHECK_HEADER([iostream])
AC_CHECK_HEADER([cstdlib])
AC_CHECK_HEADER([cstddef])

AM_CONDITIONAL(RUN_TESTS, [test "x$enable_tests" = xyes])
AM_CONDITIONAL(RUN_TESTS_WITH_CPPUTEST, [test "x$enable_cpputest" = xyes])
AM_CONDITIONAL(RUN_TESTS_WITH_CPPUNIT, [test "x$enable_cppunit" = xyes])
AM_CONDITIONAL(RUN_COVERAGE, [test "x$enable_coverage" = xyes])

AC_OUTPUT
