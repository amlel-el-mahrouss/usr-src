#include "assert.h"

// taken from the C header <gui.h>

#ifndef NULLWND
#define NULLWND ((int)0)
#endif

extern "C" void message_box(int window_id, const char* title, const char* message, int flags);

void __crt_assert(const char* message, const char* expr, const char* file)
{
    (void)expr;
    (void)file;

    message_box(NULLWND, "C/C++ Runtime (INT 3)", message, 0);
    asm volatile ("int $3"); // just raise this interrupt, the program will crash.
}
