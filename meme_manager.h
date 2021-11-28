//
// Created by DaNTe on 28.11.2021.
//

#ifndef OS3_MEME_MANAGER_H
#define OS3_MEME_MANAGER_H

#include "segmentation_manager.h"

bool init_memory(int count, int size);

void get_memory_by_bytes(int size);

struct virtual_address get_memory();

bool free_memory(struct virtual_address address);

void write_memory(struct virtual_address address, void *copy_from, int size);

void read_memory(struct virtual_address address, void *copy_to, int size);

#endif //OS3_MEME_MANAGER_H
