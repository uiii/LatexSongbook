# libtar/Makefile.  Generated from Makefile.in by configure.

### Path settings
srcdir		= .
top_srcdir	= ..
prefix		= /usr/local
exec_prefix	= ${prefix}
bindir		= ${exec_prefix}/bin
libdir		= ${exec_prefix}/lib
includedir	= ${prefix}/include

PACKAGE_NAME	= libtar
PACKAGE_VERSION	= 1.2.11



### Installation programs and flags
INSTALL		= /bin/install -c
INSTALL_PROGRAM	= ${INSTALL} -s
INSTALL_DATA	= ${INSTALL} -m 644
LN_S		= ln -s
MKDIR		= mkdir -p -m 755

### Compiler and link options
CC		= gcc
CPPFLAGS	= -I.. \
		  -I../lib \
		  -I../listhash \
		  -I${top_srcdir}/lib \
		  -I${top_srcdir}/compat \
		  
CFLAGS		= -g -O2
LDFLAGS		= 
LIBS		= -lz 
LIBOBJS		=  strlcpy$U.o basename$U.o dirname$U.o strlcpy$U.o strmode$U.o
RANLIB		= ranlib




### Makefile rules - no user-servicable parts below

LIBTAR_OBJS	= libtar.o
LIBTAR_HDRS	= ../config.h \
		  ${top_srcdir}/compat/compat.h \
		  ${top_srcdir}/lib/libtar.h \
		  ../listhash/libtar_listhash.h
LIBTAR_LIBS	= ../lib/libtar.a
ALL		= libtar


all: ${ALL}

.PHONY: clean distclean install

libtar: ${LIBTAR_OBJS} ${LIBTAR_LIBS} ${LIBTAR_HDRS}
	${CC} ${CFLAGS} ${LDFLAGS} -o libtar libtar.o ${LIBTAR_LIBS} ${LIBS}

${LIBTAR_OBJS}: ${LIBTAR_HDRS}

.c.o:
	${CC} ${CFLAGS} ${CPPFLAGS} -c -o $@ $<

clean:
	rm -f *~ *.o ${ALL} core

distclean: clean
	rm -f Makefile

install: ${ALL}
	${MKDIR} ${DESTDIR}${bindir}
	${INSTALL_PROGRAM} libtar ${DESTDIR}${bindir}

