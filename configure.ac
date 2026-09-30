AC_PREREQ([2.68])
AC_INIT([robotito], [0.0.1], [yadickson@gmail.com])
AC_CANONICAL_HOST

AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([gnu foreign subdir-objects])

AC_LANG(C++)
AC_PROG_CXX
LT_INIT([static])

AC_MSG_CHECKING([Detected Host OS])
AC_MSG_RESULT($host_os)

m4_ifdef([AX_CXX_COMPILE_STDCXX],
	[ AX_CXX_COMPILE_STDCXX(14, [noext], [mandatory]) ],
	[
	    AC_MSG_WARN([AX_CXX_COMPILE_STDCXX macro not found])

	    m4_ifdef([AX_CXX_COMPILE_STDCXX_14],
        	[ AX_CXX_COMPILE_STDCXX_14 ],
        	[ AC_MSG_WARN([AX_CXX_COMPILE_STDCXX_14 macro not found]) ]
        )
	]
)

CUSTOM_CXXFLAGS="-W -Wall -Werror -Wno-pragma-once-outside-header"

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

AC_CHECK_PROGS([CFORMAT], [clang-format], [no])
AC_CHECK_PROGS([CLINT], [clang-tidy], [no])
AC_CHECK_PROGS([CPPCHECK], [cppcheck], [no])

AS_VAR_IF([CFORMAT], [no], [AC_MSG_WARN([clang-format is required to format static code])], [])
AS_VAR_IF([CLINT], [no], [AC_MSG_WARN([clang-tidy is required to check static code])], [])
AS_VAR_IF([CPPCHECK], [no], [AC_MSG_WARN([cppcheck is required to check static code])], [])

PKG_CHECK_MODULES([DEPENDENCIES], [ncursesw])

AC_MSG_CHECKING([tests])
AC_ARG_ENABLE([tests],[AS_HELP_STRING([--disable-tests], [Disable tests])], [enable_tests=no], [enable_tests=yes])
AC_MSG_RESULT($enable_tests)

PKG_CHECK_EXISTS([cpputest], [run_test=yes], [run_test=no])

if test "x$run_test" = xyes && test "x$enable_tests" = xyes; then

	PKG_CHECK_MODULES([TEST_DEPENDENCIES_CPPUTEST], [cpputest])

	AC_MSG_CHECKING([coverage])
	AC_ARG_ENABLE([coverage],[AS_HELP_STRING([--disable-coverage], [Disable coverage])], [enable_coverage=no], [enable_coverage=yes])
	AC_MSG_RESULT($enable_coverage)

	if test "x$enable_coverage" = xyes; then
        AC_CHECK_TOOL([GCOV], [gcov], [no])
		AC_CHECK_PROGS([LCOV], [lcov], [no])
        AC_CHECK_PROGS([GENHTML], [genhtml], [no])

		AS_VAR_IF([GCOV], [no], [AC_MSG_WARN([gcov is required])], [])
		AS_VAR_IF([LCOV], [no], [AC_MSG_WARN([lcov is required])], [])
		AS_VAR_IF([GENHTML], [no], [AC_MSG_WARN([genhtml is required])], [])
	fi

fi

AC_CHECK_HEADER([clocale])
AC_CHECK_HEADER([iostream])
AC_CHECK_HEADER([cstdlib])
AC_CHECK_HEADER([cstddef])
AC_CHECK_HEADER([cctype])
AC_CHECK_HEADER([memory])

AM_CONDITIONAL(RUN_TESTS, [test "x$run_test" = xyes && test "x$enable_tests"])
AM_CONDITIONAL(RUN_COVERAGE, [test "x$LCOV" != xno && test "x$GENHTML" != xno && test "x$enable_coverage" = xyes])
AM_CONDITIONAL(RUN_FORMAT, [test "x$CFORMAT" != xno])
AM_CONDITIONAL(RUN_LINT, [test "x$CLINT" != xno])
AM_CONDITIONAL(RUN_CPPCHECK, [test "x$CPPCHECK" != xno])

AC_OUTPUT