AC_INIT([robotito], [0.0.1], [yadickson@gmail.com])

AM_INIT_AUTOMAKE

AC_LANG(C++)
AC_PROG_CXX

AC_CONFIG_FILES([Makefile])

AC_CHECK_PROG(PKG_CONFIG_EXISTS,[pkg-config],[pkg-config],[no])
AS_IF([test x"$PKG_CONFIG_EXISTS" = x"no"], [AC_MSG_ERROR([Please install 'pkg-config'.])])

PKG_CHECK_MODULES([DEPENDENCIES], [ncurses])

AC_OUTPUT
