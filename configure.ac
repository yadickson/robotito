AC_PREREQ([2.68])
AC_INIT([robotito], [0.0.1], [yadickson@gmail.com])
AC_CANONICAL_HOST

AM_INIT_AUTOMAKE([gnu foreign subdir-objects])

AC_LANG(C++)
AC_PROG_CXX

AX_CXX_COMPILE_STDCXX_11

STDCXX_CXXFLAGS="c++11"
CUSTOM_CXXFLAGS="-std=${STDCXX_CXXFLAGS} -W -Wall -Werror -Wno-pragma-once-outside-header"

AC_SUBST([STDCXX_CXXFLAGS])
AC_SUBST([CUSTOM_CXXFLAGS])

AC_PROG_INSTALL
AC_CONFIG_HEADERS([config.h])

AM_EXTRA_RECURSIVE_TARGETS([
	test
	coverage
	format
	lint
	])

AC_CONFIG_FILES([
	Makefile
	src/Makefile
	test/Makefile
	])

PKG_PROG_PKG_CONFIG

AC_CHECK_PROGS([CFORMAT], [clang-format], [yes], [])
AC_CHECK_PROGS([CLINT], [clang-tidy], [yes], [])
AC_CHECK_PROGS([CPPCHECK], [cppcheck], [yes], [])

AS_VAR_IF([CFORMAT], [clang-format], [], [AC_MSG_WARN([clang-format is required to format static code])])
AS_VAR_IF([CLINT], [clang-tidy], [], [AC_MSG_WARN([clang-tidy is required to check static code])])
AS_VAR_IF([CPPCHECK], [cppcheck], [], [AC_MSG_WARN([cppcheck is required to check static code])])

PKG_CHECK_MODULES([DEPENDENCIES], [ncursesw])

AC_MSG_CHECKING([tests enabled])
AC_ARG_ENABLE([tests],[AS_HELP_STRING([--disable-tests], [Disable tests])], [enable_tests=no], [enable_tests=yes])
AC_MSG_RESULT($enable_tests)

PKG_CHECK_EXISTS([ncursesw], [], [AC_MSG_ERROR [ncursesw is required]])

if test "x$enable_tests" = xyes; then

	PKG_CHECK_EXISTS([cpputest], [], [AC_MSG_ERROR [cpputest is required]])
	PKG_CHECK_MODULES([TEST_DEPENDENCIES_CPPUTEST], [cpputest])

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

AC_CHECK_HEADER([clocale])
AC_CHECK_HEADER([iostream])
AC_CHECK_HEADER([cstdlib])
AC_CHECK_HEADER([cstddef])
AC_CHECK_HEADER([cctype])

AM_CONDITIONAL(RUN_TESTS, [test "x$enable_tests" = xyes])
AM_CONDITIONAL(RUN_COVERAGE, [test "x$enable_coverage" = xyes])
AM_CONDITIONAL(RUN_FORMAT, [test "x$CFORMAT" = xclang-format])
AM_CONDITIONAL(RUN_TIDY, [test "x$CLINT" = xclang-tidy])
AM_CONDITIONAL(RUN_CPPCHECK, [test "x$CPPCHECK" = xcppcheck])

AC_OUTPUT