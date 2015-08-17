#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])

dnl ===========================================================================

m4_define(glib_minver,                 2.43.4)
m4_define(gtk_minver,                  3.16.0)

dnl ===========================================================================

AC_INIT([gorex], [0.1], [trifonovkv@gmail.com])
AC_CONFIG_SRCDIR([src/gorex-main.c])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
PKG_CHECK_MODULES(BASE, [
	gtk+-3.0 >= gtk_minver
	glib-2.0 >= glib_minver
])
# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([
	Makefile
	src/Makefile
	data/Makefile
	data/icons/Makefile
])
AC_OUTPUT

dnl ==========================================================================
echo "
gtkwindow-$VERSION:

	prefix:			${prefix}
	source code location:	${srcdir}
	compiler:		${CC}
	
	gtk+-3.0:		$(pkg-config --modversion gtk+-3.0)
	glib-2.0:		$(pkg-config --modversion glib-2.0)
"
