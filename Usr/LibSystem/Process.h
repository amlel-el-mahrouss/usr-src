#ifndef __SYS_PROCESS_H__
#define __SYS_PROCESS_H__

#include <Gorm/Foundation.hpp>

typedef Skoch::voidPtr bundle_t;
typedef Skoch::voidPtr sym_t;
typedef Skoch::Int thread_t;

extern "C" sym_t bundle_sym_get(bundle_t bundle, const char* symbolName);
extern "C" bundle_t bundle_open(const char* path);
extern "C" bool bundle_close(bundle_t bundle);

extern "C" thread_t thread_run(void(*your_thread)(int argc, char* argv[]));
extern "C" thread_t process_open(const char* name);
extern "C" bool thread_detach(thread_t id);
extern "C" bool thread_wait(thread_t id, Skoch::Int ms);
extern "C" thread_t thread_fork(thread_t id);

#endif // !__SYS_PROCESS_H__
