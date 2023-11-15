AC_INIT([robotito], [0.0.1], [yadickson@gmail.com])

AM_INIT_AUTOMAKE

AC_LANG(C++)
AC_PROG_CXX

AC_CONFIG_FILES([
	Makefile
	src/Makefile
	test/Makefile
])

PKG_PROG_PKG_CONFIG

PKG_CHECK_EXISTS([ncursesw], [], [AC_MSG_ERROR("can't find ncursesw")])
PKG_CHECK_EXISTS([cppunit], [], [AC_MSG_ERROR("can't find cppunit")])

PKG_CHECK_MODULES([DEPENDENCIES], [ncursesw])
PKG_CHECK_MODULES([TEST_DEPENDENCIES], [cppunit])

AC_OUTPUT
