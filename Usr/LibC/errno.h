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

typedef int errno_t;

extern "C" errno_t errno;

#define	EPERM		1		/* Operation not permitted */
#define	ENOENT		2		/* No such file or directory */
#define	ESRCH		3		/* No such process */
#define	EINTR		4		/* Interrupted system call */
#define	EIO		    5		/* Input/output error */
#define	ENXIO		6		/* Device not configured */
#define	E2BIG		7		/* Argument list too long */
#define	ENOEXEC		8		/* Exec format error */
#define	EBADF		9		/* Bad file descriptor */
#define	ECHILD		10		/* No child processes */
#define	EDEADLK		11		/* Resource deadlock avoided */
                    /* 11 was EAGAIN */
#define	ENOMEM		12		/* Cannot allocate memory */
#define	EACCES		13		/* Permission denied */
#define	EFAULT		14		/* Bad address */

#define	EFBIG		27		/* File too large */
#define	ENOSPC		28		/* No space left on device */
#define	ESPIPE		29		/* Illegal seek */
#define	EROFS		30		/* Read-only filesystem */
#define	EMLINK		31		/* Too many links */
#define	EPIPE		32		/* Broken pipe */

/* math software */
#define	EDOM		33		/* Numerical argument out of domain */
#define	ERANGE		34		/* Result too large */

/* non-blocking and interrupt i/o */
#define	EAGAIN		35		/* Resource temporarily unavailable */
