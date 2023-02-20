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

enum SYSCALLS {
    OPEN_DEV,
    CLOSE_DEV,
    OPEN_FILE,
    CLOSE_FILE,
    OPEN_PROCESS,
    CLOSE_PROCESS,
    CONTROL_PROCESS,
    CONTROL_DEV,
    CONTROL_FILE,
    OPEN_IPC,
    CLOSE_IPC,
    SEND_IPC,
    RECV_IPC,
    OPEN_TCP,
    CLOSE_TCP,
    RECV_TCP,
    OPEN_UDP,
    CLOSE_UDP,
    RECV_UDP,
    SYSTEM_VER,
    SYSTEM_ASK_SHUTDOWN,
    SYSTEM_ASK_REBOOT,
    SYSTEM_ASK_SUPER,
    SYSTEM_ASK_FOR_POOL,
    SYSTEM_FREE_MY_POOL,
};

#include <stdarg.h>

extern "C" long int syscall(int id, ...);
