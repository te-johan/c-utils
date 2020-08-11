/*
 * Copyright (c) 2020 Siddharth Chandrasekaran <siddharth@embedjournal.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _HASHMAP_H_
#define _HASHMAP_H_

#include <stdint.h>
#include <stddef.h>

typedef struct hash_map_item_s hash_map_item_t;

struct hash_map_item_s {
	hash_map_item_t *next;
	uint32_t hash;
	char *key;
	void *val;
};

typedef struct {
	hash_map_item_t **pool;
	size_t capacity;
	size_t count;
} hash_map_t;

typedef void (*hash_map_callback_t)(const char *key, void *val);

void hash_map_init(hash_map_t *map);
void hash_map_free(hash_map_t *map, hash_map_callback_t cb);
void hash_map_insert(hash_map_t *map, const char *key, void *val);
void *hash_map_get(hash_map_t *map, const char *key);
void *hash_map_delete(hash_map_t *map, const char *key);
void hash_map_foreach(hash_map_t *map, hash_map_callback_t cb);

#endif /* _HASHMAP_H_ */
