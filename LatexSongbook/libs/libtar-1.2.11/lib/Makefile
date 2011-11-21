# lib/Makefile.  Generated from Makefile.in by configure.

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
CPPFLAGS	= -I. \
		  -I.. \
		  -I${srcdir} \
		  -I${top_srcdir}/compat \
		  -I../listhash \
		  
CFLAGS		= -g -O2
LDFLAGS		= 
LIBS		= -lz 
LIBOBJS		=  strlcpy$U.o basename$U.o dirname$U.o strlcpy$U.o strmode$U.o
RANLIB		= ranlib

VPATH		= ../compat:../listhash


### Makefile rules - no user-servicable parts below

LIBTAR_OBJS	= append.o \
		  block.o \
		  decode.o \
		  encode.o \
		  extract.o \
		  handle.o \
		  libtar_hash.o \
		  libtar_list.o \
		  output.o \
		  util.o \
		  wrapper.o
LIBTAR_HDRS	= ../config.h \
		  ${top_srcdir}/compat/compat.h \
		  ${srcdir}/libtar.h \
		  ${srcdir}/internal.h \
		  ../listhash/libtar_listhash.h
LIBTAR_LIBS	= ./libtar.a
ALL		= libtar.a

DISTCLEANFILES	= ../listhash/libtar_listhash.h \
		  ../listhash/libtar_list.c \
		  ../listhash/libtar_hash.c


all: ${ALL}

.PHONY: clean distclean install

libtar.a: ${LIBTAR_OBJS} ${LIBOBJS}
	${AR} rc libtar.a ${LIBTAR_OBJS} ${LIBOBJS}
	${RANLIB} libtar.a

${LIBTAR_OBJS}: ${LIBTAR_HDRS}

.c.o:
	${CC} ${CFLAGS} ${CPPFLAGS} -c -o $@ $<

clean:
	rm -f *~ *.o ${ALL} core

distclean: clean
	rm -f Makefile ${DISTCLEANFILES}

install: ${ALL}
	${MKDIR} ${DESTDIR}${libdir}
	${INSTALL_DATA} libtar.a ${DESTDIR}${libdir}
	${MKDIR} ${DESTDIR}${includedir}
	${INSTALL_DATA} ${srcdir}/libtar.h ${DESTDIR}${includedir}
	${INSTALL_DATA} ../listhash/libtar_listhash.h ${DESTDIR}${includedir}

