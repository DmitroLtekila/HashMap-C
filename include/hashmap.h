#ifndef HASHMAP_H
#define HASHMAP_H

#include "generic_types.h"

typedef struct HashMap HashMap;

typedef void* (*CopyFunction)(void* value);
typedef void (*FreeFunction)(void* value);
typedef void (*PrintFunction)(void* value);

HashMap* newHashMap(CopyFunction copyValue, FreeFunction freeValue, PrintFunction printValue);
void HashMap_put(HashMap* map, char* key, void* value);
void* HashMap_get(HashMap* map, char* key);
void HashMap_remove(HashMap* map, char* key);
void HashMap_print(HashMap* map);
void HashMap_free(HashMap* map);

#endif