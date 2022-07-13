# Copyright (c) 2022 ARM Limited. All rights reserved.
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.19.0)

set(MBED_PATH ${CMAKE_CURRENT_SOURCE_DIR}/mbed-os CACHE INTERNAL "")
set(MBED_CONFIG_PATH ${CMAKE_CURRENT_BINARY_DIR} CACHE INTERNAL "")
set(APP_TARGET test)

include(${MBED_PATH}/tools/cmake/app.cmake)

project(${APP_TARGET})

add_subdirectory(${MBED_PATH})

set(SOURCES 
	BaseClasses.cpp
	Bitcoin.cpp
	BitcoinCurve.cpp
	Conversion.cpp
	Electrum.cpp
	Hash.cpp
	HDWallet.cpp
	PSBT.cpp
	Script.cpp
	Transaction.cpp
	utility/segwit_addr.c
	utility/trezor/address.c
	utility/trezor/base58.c
	utility/trezor/bignum.c
	utility/trezor/bip39.c
	utility/trezor/ecdsa.c
	utility/trezor/hasher.c
	utility/trezor/hmac.c
	utility/trezor/memzero.c
	utility/trezor/pbkdf2.c
	utility/trezor/rand.c
	utility/trezor/rfc6979.c
	utility/trezor/ripemd160.c
	utility/trezor/secp256k1.c
	utility/trezor/sha2.c
	utility/trezor/sha3.c
)

add_library(bitcoin STATIC ${SOURCES})

add_executable(${APP_TARGET}
    main.cpp
)

target_link_libraries(${APP_TARGET} mbed-os bitcoin)

mbed_set_post_build(${APP_TARGET})

option(VERBOSE_BUILD "Have a verbose build process")
if(VERBOSE_BUILD)
    set(CMAKE_VERBOSE_MAKEFILE ON)
endif()