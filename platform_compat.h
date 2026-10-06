/*
 * Copyright (C) 2011-2026 Redis Labs Ltd.
 *
 * This file is part of memtier_benchmark.
 *
 * memtier_benchmark is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2.
 *
 * memtier_benchmark is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MEMTIER_PLATFORM_COMPAT_H
#define MEMTIER_PLATFORM_COMPAT_H

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#include <afunix.h>
#include <assert.h>
typedef long suseconds_t;

// mingw-w64's assert() expands to _assert(), which is not declared noreturn
// (glibc's __assert_fail is). Without this, every "assert(0);" used as the
// body of a value-returning function trips -Wreturn-type. Redeclare it with
// the attribute; protocol.h includes this header so the redeclaration is in
// effect before its inline bodies.
extern "C" __declspec(dllimport) void __attribute__((__noreturn__, __cdecl__))
_assert(const char *_Message, const char *_File, unsigned _Line);
#else
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#endif

#endif
