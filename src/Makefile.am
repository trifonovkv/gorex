bin_PROGRAMS = gorex

UI_FILES = 							\
	gorex-window.ui					\
	$(NULL)

gorex-resources.c: gorex.gresource.xml $(UI_FILES)
	glib-compile-resources --target=$@ --sourcedir=$(srcdir) --generate-source \
                                    --c-name gorex $(srcdir)/gorex.gresource.xml

gorex_CFLAGS = `pkg-config --cflags gtk+-3.0 --libs gtk+-3.0`

BUILT_SOURCES = 					\
	gorex-resources.c 			    \
	$(NULL)

gorex_SOURCES = 					\
	gorex-main.c 					\
	gorex-application.h 		    \
	gorex-application.c 		    \
	gorex-window.h 					\
	gorex-window.c 					\
	$(NULL)

nodist_gorex_SOURCES = 		        \
	$(BUILT_SOURCES) 				\
	$(NULL)

CLEANFILES = 						\
	$(BUILT_SOURCES)				\
	$(NULL)

EXTRA_DIST =						\
	$(UI_FILES)						\
	gorex.gresource.xml			    \
	$(NULL)

-include $(top_srcdir)/git.mk
