#ifndef __SYS_DIR_H__
#define __SYS_DIR_H__

#include <Gorm/Foundation.hpp>

typedef int dir_t;

extern "C" dir_t dir_open(const char* path, int acl);
extern "C" void dir_close(dir_t node);

extern "C" void dir_remove(dir_t node, bool recur, bool force);

typedef int node_t;
extern "C" node_t dir_create(node_t node, const char* name, int as);

extern "C" bool node_copy(node_t nod, const char* newPath);
extern "C" bool node_move(node_t nod, const char* newPath);

#endif /* __SYS_DIR_H__ */
