# Makefile.  Generated from Makefile.in by configure.

### Path settings
prefix		= /usr/local
exec_prefix	= ${prefix}
bindir		= ${exec_prefix}/bin
mandir		= ${prefix}/man
libdir		= ${exec_prefix}/lib
includedir	= ${prefix}/include
top_srcdir	= .

PACKAGE_NAME	= libtar
PACKAGE_VERSION	= 1.2.11





INSTALL		= /bin/install -c
INSTALL_DATA	= ${INSTALL} -m 644

SUBDIRS = lib libtar doc

all:
	for n in $(SUBDIRS); do \
		( cd $$n && $(MAKE) $@ $(MAKE_FLAGS) ) || exit 1; \
	done

.PHONY: install install-recurse postinstall-encap clean distclean

install: install-recurse 

install-recurse:
	for n in $(SUBDIRS); do \
		( cd $$n && $(MAKE) install $(MAKE_FLAGS) ) || exit 1; \
	done

postinstall-encap:
	

clean:
	for n in $(SUBDIRS); do \
		( cd $$n && $(MAKE) $@ $(MAKE_FLAGS) ) || exit 1; \
	done

distclean:
	for n in $(SUBDIRS); do \
		( cd $$n && $(MAKE) $@ $(MAKE_FLAGS) ) || exit 1; \
	done
	rm -f config.cache config.log config.status config.h Makefile

