/*
 *	========================================================
 *
 *	GORM
 * 	Date Added: 08/01/2023
 * 	Copyright SKOCH Computer Division, all rights reserved.
 *
 * 	========================================================
 */

#pragma once

void __crt_assert(const char* msg, const char* expr, const char* file);

#ifndef __CRT_NO_DEBUG__
#define assert(EXPR) \
    if (!(EXPR))\
        __crt_assert("Expression failed!",  # EXPR, __FILE__);\


#else

#define assert(EXPR)

#endif
