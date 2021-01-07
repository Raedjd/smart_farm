## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = nbre_troupeaux

nbre_troupeaux_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h\
	nbre_troupeaux.c nbre_troupeaux.h

nbre_troupeaux_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

