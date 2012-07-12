ifndef config
    config=debug
endif

# VARIABLES
export BASE_DIR=$(shell dirname $(shell readlink -f $(lastword $(MAKEFILE_LIST))))

export CONFIG_DIR=${BASE_DIR}/config
export BUILD_DIR=${BASE_DIR}/build
export BIN_DIR=${BASE_DIR}/bin
export TOOLS_DIR=${BASE_DIR}/tools

PREMAKE:=${TOOLS_DIR}/premake4-$(shell uname -m)

ifeq ($(config),debug)
    GDB=gdb -ex 'r'
	GDB_ARG=gdb -ex
endif

ifndef install_prefix
    INSTALL_PREFIX=/usr/local
else
    INSTALL_PREFIX=$(shell readlink -f $(install_prefix))
endif
export INSTALL_PREFIX

# TARGETS

.PHONY: all configure build clean

all: configure build

configure: ${BUILD_DIR}/Makefile

${BUILD_DIR}/Makefile: premake4.lua
	@rm -rf ${BUILD_DIR}
	@mkdir -p ${BUILD_DIR}
	@cd ${BUILD_DIR} && ${PREMAKE} --file=${BASE_DIR}/premake4.lua --to gmake

build: configure
	@cd ${BUILD_DIR} && ${MAKE} config=$(config) --no-print-directory

run:
	-@${GDB} ${BIN_DIR}/LatexSongbook

run-song-editor:
	-@${GDB_ARG} 'r --song-editor' ${BIN_DIR}/LatexSongbook
	
run-songbook-editor:
	-@${GDB_ARG} 'r --songbook-editor' ${BIN_DIR}/LatexSongbook

install:
#@${MAKE} -f ${CONFIG_DIR}/install/install.mk --no-print-directory

uninstall:
#@${MAKE} -f ${CONFIG_DIR}/install/uninstall.mk --no-print-directory

clean:
	@echo "Cleaning..."
	-@if [ -f ${BUILD_DIR}/Makefile ]; \
		then cd ${BUILD_DIR} && ${MAKE} clean --no-print-directory; \
	fi
	@rm -rf bin
	@rm -rf lib
	@rm -rf build
	@echo "Done."
